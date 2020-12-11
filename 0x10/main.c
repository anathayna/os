#define FUSE_USE_VERSION 26
#define HEADER_SIZE 54

#include <fuse.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

static const char *filepath = "/file";
static const char *filename = "file";
static const char *filecontent = "you got a secret! can you keep it?";

int get_image(FILE* bmp) {
    fseek(bmp, 10, 0);
    int offset;
    offset = (int)fgetc(bmp);
    return offset;
}

static int getattr_callback(const char *path, struct stat *stbuf) {
    memset(stbuf, 0, sizeof(struct stat));

    if (strcmp(path, "/") == 0) {
        stbuf->st_mode = S_IFDIR | 0755;
        stbuf->st_nlink = 2;
        return 0;
    }

    if (strcmp(path, filepath) == 0) {
        stbuf->st_mode = S_IFREG | 0777;
        stbuf->st_nlink = 1;
        stbuf->st_size = strlen(filecontent);
        return 0;
    }

    return -ENOENT;
}

static int readdir_callback(const char *path, void *buf, fuse_fill_dir_t filler,
    off_t offset, struct fuse_file_info *fi) {
    (void) offset;
    (void) fi;

    filler(buf, ".", NULL, 0);
    filler(buf, "..", NULL, 0);
    filler(buf, filename, NULL, 0);

    return 0;
}

static int open_callback(const char *path, struct fuse_file_info *fi) {
    return 0;
}

static int read_callback(const char *path, char *buf, size_t size, off_t offset,
    struct fuse_file_info *fi) {

    if (strcmp(path, filepath) == 0) {
        size_t len = strlen(filecontent);
        if (offset >= len) {
            return 0;
        }

        if (offset + size > len) {
            memcpy(buf, filecontent + offset, len - offset);
            return len - offset;
        }

        memcpy(buf, filecontent + offset, size);
        return size;
    }

    return -ENOENT;
}

static struct fuse_operations main_operations = {
    .getattr = getattr_callback,
    .open = open_callback,
    .read = read_callback,
    .readdir = readdir_callback,
};

int main(int argc, char *argv[]) {
    fuse_main(argc, argv, &main_operations, NULL);
    unsigned char bmp[] = { 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80 };
    
    FILE *file;
    FILE *message;
    FILE *secret;

    file=fopen(argv[2], "r");
    if (file == NULL) {
        fprintf(stderr, "error ao abrir o arquivo %s\n", argv[2]);
        return -1;
    }

    secret=fopen(argv[3], "w");
    if (secret== NULL) {
        fprintf(stderr, "error ao esteganografar o segredo %s\n", argv[3]);
        return -1;
    }

    int offset = get_image(file);

	rewind(file);

	for(int i=0; i<offset; i++) {
		tmp = fgetc(file);
		fputc(tmp, secret);
	}

    char file_buffer; 
    
	for(int i=0;i<message;i++) {
		char tmp='\0';
			for( int j=0;j<8;j++) {
				tmp = tmp<<1;
				file_buffer = fgetc(file);
				int file_byte_lsb = file_buffer & 1; 
				tmp |= file_byte_lsb;
			}
		fputc(tmp, message);
	}
    
    fclose(file);
    fclose(message);
    fclose(secret);

    return(EXIT_SUCCESS);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *criar(void);

int main(void) {
    char *b;
    for(int i=0; i<10; i++) {
        b = criar();
        puts(b);
        free(b);
    }
}

void *criar(void) {
    char *buf;
    buf = (char *) malloc(80);
    strcpy(buf, "ana thayna");
    return buf;
}

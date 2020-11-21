#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

char memory[2048];

struct mem {
  size_t size;
  int free; 
  struct mem *next; 
};

struct mem *m = (void *)memory;

void *alloc(size_t nbytes);
void free(void *p);
void init();

int main(void) {
    init();
    int *p = (int *) alloc(4*sizeof(int));
    *p = 100;

    printf("[1] p = %d\n", *p);
    printf("[2] p memory: %p\n", p);
    
    free(p);
}

void init() {
    m->size = sizeof(memory) - sizeof(struct mem);
    m->free = 1;
    m->next = NULL;
}

void *alloc(size_t nbytes) {
    struct mem *this, *after;
    void *resul;
    this = m;

    //void *n = malloc(nbytes);

    while(this->size < nbytes || (this->free == 0 && this->next != NULL)) { 
        after = this;
        this = this->next;
    }

    printf("[3] memory: %p\n", this);

    if(this->size > nbytes || this->size == nbytes) {
        this->free = 0;
        resul = this++; 
        return resul;
    } else {
        resul = NULL;
        return resul;
    }

    return NULL;
}

void free(void *p) {
    if(p >= (void *)memory && p <= (void *)(memory + sizeof(memory))) {
        struct mem *this = p;
        this--;
        this->free = 1;
    } else {
        exit(EXIT_FAILURE);
    }
    printf("[4] free: %p\n", free);
}

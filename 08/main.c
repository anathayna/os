#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

struct point {
  size_t size;
  int free; 
  struct point *next; 
};

void *alloc(size_t nbytes);
void free(void *p);
void init();

char memory[2048];
struct point *m = (void *)memory;

int main(void) {
    init();
    int *p = (int *) alloc(4*sizeof(int));
    *p = 100;

    printf("[1] p = %d\n", *p);
    printf("[1] p memory: %d\n", p);
    
    free(p);
}

void init() {
    m->size = memory - sizeof(struct point);
    m->free = 1;
    m->next = NULL;
}

void *alloc(size_t nbytes) {
    struct point *this, *after;
    void *resul;
    this = m;

    //void *n = malloc(nbytes);

    while(this->size < nbytes || (this->free == 0 && this->next != NULL)) { 
        after = this;
        this = this->next;
    }

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
    if (p != NULL) {
        free(p);
    }
}
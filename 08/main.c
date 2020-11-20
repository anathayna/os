#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

struct point {
  size_t size;
  int free; 
  struct point *next; 
};

void *alloc(int nbytes);
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
    //m->size = sizeof(memory) - sizeof(struct point);
    m->size = memory - sizeof(struct point);
    m->free = 1;
    m->next = NULL;
}

void *alloc(int nbytes) {
    void *n = malloc(nbytes);
    return n;
}

void free(void *p) {
    if (p != NULL) {
        free(p);
    }
}
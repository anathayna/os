#include <stdio.h>
#include <stdlib.h>

void *alloc(int nbytes);
void free(void *p);

int main(void) {
    int *p = (int *) alloc(4*sizeof(int));
    *p = 100;

    printf("[1] p: %d\n", *p);
    printf("[1] p: %d\n", p);
    
    free(p);
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
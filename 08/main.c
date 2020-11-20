#include <stdio.h>

void *maloc(int nbytes);
void free(void *p);

int main(void) {
    int *p = (int *) maloc(4*sizeof(int));
    *p = 100;
    free(p);
}

void *maloc(int nbytes) {
    return NULL;
}

void free(void *p) {
    return NULL;
}
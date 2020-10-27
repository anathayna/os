#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *criar(void);

int main(void) {
    char *b;
    b = criar();
    puts(b);
}

void *criar(void) {
    char *buf;
    buf = (char *) malloc(80);
    strcpy(buf, "ana thayna");
    return buf;
}

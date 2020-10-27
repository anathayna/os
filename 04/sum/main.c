#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

void *imprimir_sum(void *);

typedef struct {
    int x;
    int y;
} parameters_t;

int main(void) {
    pthread_t th;
    parameters_t p;
    p.x = 10;
    p.y = 20;

    pthread_create(&th, NULL, imprimir_sum, &p);
    pthread_join(th, NULL);
    exit(EXIT_SUCCESS);
}

void *imprimir_sum(void *s) {
    parameters_t p = *((parameters_t *) s);
    printf("%d + %d = %d\n", p.x, p.y, p.x + p.y);
    return NULL;
}

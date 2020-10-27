#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#define N_THREADS 15

void alfa(void);
void *imprimir_msg(void *msg);

int main(void) {
    alfa();
    sleep(3);
    exit(EXIT_SUCCESS);
}

void alfa(void) {
    pthread_t th[N_THREADS];
    int thn[N_THREADS];

    for(int i=0; i<N_THREADS; i++) {
        thn[i] = i;
        pthread_create(&th[i], NULL, imprimir_msg, &thn[i]);
    }

    for(int i=0; i<N_THREADS; i++) {
        pthread_join(th[i], NULL);
    }
}

void *imprimir_msg(void *m) {
    int id = *((int *) m);
    printf("estou na thread %d na função %s\n", id, __FUNCTION__);
    return NULL;
}

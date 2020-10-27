#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#define N_THREADS 15

void *imprimir_msg(void *msg);

int main(void) {
    pthread_t th[N_THREADS];

    for(int i=0; i<N_THREADS; i++) {
        pthread_create(&th[i], NULL, imprimir_msg, NULL);
    }

    for(int i=0; i<N_THREADS; i++) {
        pthread_join(&th[i], NULL);
    }
    
    //spleep(1);
    exit(EXIT_SUCCESS);
}

void *imprimir_msg(void *msg) {
    printf("estou na função %s\n", __FUNCTION__);
    return NULL;
}

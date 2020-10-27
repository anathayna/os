#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

void *imprimir_msg(void *msg);

int main(void) {
    pthread_t th1;
    pthread_create(&th1, NULL, imprimir_msg, NULL);
    sleep(1);
    exit(EXIT_SUCCESS);
}

void *imprimir_msg(void *msg) {
    printf("estou na função %s\n", __FUNCTION__);
    return NULL;
}

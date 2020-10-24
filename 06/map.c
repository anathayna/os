#include <stdio.h>
#include <stdlib.h>

void **map(void **itens, void * (*f) (void *), int nr_itens) {

    void **resultados = malloc(sizeof(void *) * nr_itens);
    if(!resultados) { return NULL; }

    for(int i=0; i<nr_itens; i++) {
        void *item = itens[i];
        void *resultado = (*f)(item);
        resultados[i] = resultado;
    }

    return resultados;
}
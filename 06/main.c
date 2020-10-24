#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"
#include "mr.h"
#define NR_ITENS 2

void *obter_tamanho_nome(void *);

int main(int argc, char *argv[]) {
    aluno_t a1 = criar_aluno("ana");
    aluno_t a2 = criar_aluno("thayna");

    aluno_t *alunos = malloc(sizeof(aluno_t) * NR_ITENS);
    alunos[0] = a1;
    alunos[1] = a2;

    printf("id: %2d | nome %-50s", aluno_id(a1), aluno_nome(a1), aluno_nome(a1) == NULL ? "" : aluno_nome(a1));
    printf("id: %2d | nome %-50s", aluno_id(a2), aluno_nome(a2), aluno_nome(a2) == NULL ? "" : aluno_nome(a2));

    liberar_aluno(a1); a1 = NULL;
    liberar_aluno(a2); a2 = NULL;

    exit(EXIT_SUCCESS);
}

void *obter_tamanho_nome(void *aluno) {
    if(!aluno) { return NULL; }

    aluno_t a = (aluno_t) aluno;
    if(!aluno_nome(a)) { return NULL; }

    int *r = malloc(sizeof(int));
    if(!r) { return NULL; }

    *r = strlen(aluno_nome(a));

    return r;
}

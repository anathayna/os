#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"

int main(int argc, char *argv[]) {
    aluno_t a1 = criar_aluno("ana");
    aluno_t a2 = criar_aluno("thayna");

    printf("id: %2d | nome %-50s", aluno_id(a1), aluno_nome(a1));
    printf("id: %2d | nome %-50s", aluno_id(a2), aluno_nome(a2));

    liberar_aluno(a1);
    liberar_aluno(a2);

    exit(EXIT_SUCCESS);
}

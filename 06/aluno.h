#ifndef __EH_ALUNO_H
#define __EH_ALUNO_H

typedef struct aluno *aluno_t;
aluno_t criar_aluno(char *nome);
int aluno_id(aluno_t);
char *aluno_nome(aluno_t);
void liberar_aluno(aluno_t);

#endif
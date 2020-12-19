#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
  char *data;
  struct no *prox;
} No;

No* init() {
  return NULL;
}

void insert(No *i, char *j) {
  No *no = (No*)malloc(sizeof(No));
  no->data = j;
  no->prox = i->prox;
  i->prox = no;
}

void print(No *n) {
  for(No* aux=n; aux!=NULL; aux=aux->prox) {
    printf("%s\n", n->data);
  }
  printf("\n");
}

No* reverse(No* l) {
  No* ant = NULL;
  No* aux = l;
  No* prox = NULL;
  
  while(aux != NULL) {
    prox = aux->prox;
    aux->prox = ant;
    ant = aux;
    aux = prox;
  }
  return ant;
}

int main(void) {
  No *l = (No*)malloc(sizeof(No));
  l = init();

  printf("digite alguns nomes: (p/ finalizar digite 'fim')\n");

  while(1) {
    char *n = (No*)malloc(sizeof(No));
    scanf("%s\n", n);

    if(strcmp(n,"fim") == 0) {
      printf("inverso:\n");
      reverse(l);
      print(l);
      break;
    } else {
      insert(l, n);
    }
    free(n);
  }
  return 0;
}

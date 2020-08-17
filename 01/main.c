#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list {
  int size;
  char *data;
  struct No *next;
  struct No *head;
}List;

void init() {
  List* l = (List*)malloc(sizeof(List));
  char names[64];
  l->size = -1;
  l->data = names;
}

void push(List* l, char *data) {
  List* no = (List*)malloc(sizeof(List));
  no->data = data;
  no->next = l->head;
  l->head = no;
  l->size++;
}

void pop(List* l) {
  List* p = l->head;
  l->head = p->next;
  free(p);
  l->size--;
}

void print(List* l) {
  List* p = l->head;
  while(p!=NULL) {
    printf("%d", p->data);
    p = p->next;
  }
  printf("\n");
}

void reverse(List *l);

int main(void) {
  init();
  return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct stringList {
  char string;
  struct stringList *next;
}sList;

typedef struct nameList {
  sList *start;
  sList *end;
}nList;

void init(nList *p){
  p->start = NULL;
  p->end = NULL;  
}

void insert(nList *p){
  sList *no;
  no = malloc (sizeof (char));
  scanf("%c",&no->string);
  no->next = NULL;

  if (p->start == NULL){
    p->start = no;
    p->end = no;  
  } else {
    p->end->next = no;
    p->end = no; 
  }
}

void reverseList(sList *e, sList *ant){
  if(e->next != NULL)
    reverseList(e->next, e);
  e->next = ant;
}

void reverse(nList *p){
  reverseList(p->start, NULL);

  sList *aux = p->start;
  p->start = p->end;    
  p->end = aux;
}

int main(void) {
  return 0;
}

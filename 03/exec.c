#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {

  printf("Listagem de diretório\n\n");
  execlp("ls", "ls", "-lha", NULL);
  perror("Não deveria passar por aqui!");
  exit(EXIT_FAILURE);

}
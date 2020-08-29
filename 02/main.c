#include <sys/utsname.h>
#include <stdio.h>

int uname(struct utsname *buf);

int main(void) {
  int i, n;

  printf("digite um número qualquer: ");
  scanf("%d", &n);

  printf("\ntabuada do %d:\n", n);
  for(i=1; i<=10; i++){
    printf("%d x %d = %d\n", i, n, i*n);
  }

  return 0;
}

#include <sys/utsname.h>
#include <stdio.h>

int uname(struct utsname *buf);

int main(void) {
  printf("Hello World\n");
  return 0;
}

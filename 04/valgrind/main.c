#include <stdio.h>
#include <stdlib.h>

//protótipo
void trace(const char *);
void func(void);

int main(void) {
    trace(__FUNCTION__);
    func();
    exit(EXIT_SUCCESS);
}

void func(void) {
    trace(__FUNCTION__);

    char *buf;
    buf = "ana thayna";
    puts(buf);
}

void trace(const char *f){
    printf("estou na função nomeada '%s'\n", f);
}

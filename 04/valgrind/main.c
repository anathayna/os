#include <stdio.h>
#include <stdlib.h>

//protótipo
void func(void);

int main(void) {
    func();
    exit(EXIT_SUCCESS);
}

void func(void){
    printf("trace func");
}

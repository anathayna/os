#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mudar(char *);

int main(void) {
    char buf[80];
    strcpy(buf, "  ana thayna");
    mudar(buf);
    puts(buf);
}

void mudar(char *s) {
    if(s != NULL) { 
        s[0] = '#';
    }
}

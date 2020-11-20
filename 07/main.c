#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#define BUFFER_SIZE 128

void initBuffer(char *buff);
void off(void);

// int main() {
//     while(1)
//         printf("*\n");
// }

int main(void) {
    unsigned int eax=11,ebx=0,ecx=1,edx=0;
    asm volatile("cpuid"
            : "=a" (eax),
              "=b" (ebx),
              "=c" (ecx),
              "=d" (edx)
            : "0"  (eax), 
              "2"  (ecx)
            : );

    int n = eax;
    int p = n - 1; 

    for (int i=0;i<p;i++) {
        fork();
    }

    off();

    return(EXIT_SUCCESS);
}

void initBuffer(char *buff) {
    for (int i=0;i<BUFFER_SIZE;) {
        buff[i] = '*';
        buff[i+1] = '\n';
        i += 2;
    }
    buff[BUFFER_SIZE - 1] = '\0';
}

void off(void) {
    char msg[BUFFER_SIZE];
    initBuffer(msg);
    start:
        puts(msg);
        goto start;
}

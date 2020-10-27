#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

void *alfa(void *);
void count(int fcount, char *fname[]);

int main(int argc, char *argv[]) {
  if (argc > 1) {
    count(argc - 1, argv);
  }
  exit(EXIT_SUCCESS);
}

void *alfa(void *fn) {
  const char *fname = (char *) fn;
  FILE *f;

  f = fopen(fname, "r");
  if (f != NULL) {
    int fsize = sizeof(f);
    char *mem = malloc(fsize);
    int word = 0;

    while (fscanf(f, "%s", mem) == 1) {
      word++;
    }
    free(mem);

    printf("%s: %d words\n", fname, word);
  } else {
    printf("file %s not found.\n", fname);
  }

  fclose(f);
  return NULL;
}


void count(int fcount, char *fname[]) {
  int nthreads = fcount;
  pthread_t t[nthreads]; 

  for (int i = 1; i <= fcount; i++) {
    pthread_create(&t[i - 1], NULL, alfa, fname[i]);
  }

  for(int i = 0; i < nthreads; i++) {
    pthread_join(t[i], NULL);
  }
}


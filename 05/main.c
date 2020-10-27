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
  FILE *file;

  int word = 0;
  int fsize = sizeof(file);
  char *mem = malloc(fsize);

  file = fopen(fname, "r");

  if(file == NULL) {
    printf("file %s not found", fname);
    exit(EXIT_FAILURE);
  }

  while (fscanf(file, "%s", mem) == 1) {
    word++;
  }
  free(mem);

  printf("%s: %d words\n", fname, word);

  fclose(file);
  return 0;
}

void count(int fcount, char *fname[]) {
  int nthreads = fcount;
  pthread_t t[nthreads]; 

  for (int i=1; i <= fcount; i++) {
    pthread_create(&t[i-1], NULL, alfa, fname[i]);
  }

  for(int i=0; i<nthreads; i++) {
    pthread_join(t[i], NULL);
  }
}


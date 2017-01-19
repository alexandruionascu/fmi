#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc, char* argv[]) {
  if (argc < 2) {
    printf("No arguments provided. \n");
    exit(EXIT_FAILURE);
  }
  int p[2];
  pipe(p);
  if (fork() == 0) {
    close(1);
    dup(p[1]);
    close(p[0]);
    close(p[1]);
    argv[argc - 3] = NULL;
    execvp(argv[1], argv + 1);

    exit(2);
  } else {
    close(0);
    dup(p[0]);
    close(p[0]);
    close(p[1]);
    printf("Number of words: ");
    fflush(stdout);
    execlp("wc", "wc", "-w", NULL);
    exit(2);
  }
  return 0;
}

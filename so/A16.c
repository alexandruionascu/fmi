#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void printEnv(char const* envVar) {
  const char* value = getenv(envVar);
  pid_t pid = getpid();
  printf("%s = %s from process %d \n", envVar, value, pid);
}


int main() {
  printEnv("TERM");

  if(setenv("TERM", "vt52", 1) != 0) {
    perror("Error setting the environment variable...\n");
    exit(EXIT_FAILURE);
  }

  if(fork() == 0)
    printEnv("TERM");

  return 0;
}

#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

void printFile(char const *fileName, int depth) {
  for (int i = 1; i <= depth; i++) {
    printf("----");
  }

  printf("%s\n", fileName);
}

int isValid(char const *dirName) {
  if (strcmp(dirName, ".") == 0)
    return 0;

  if (strcmp(dirName, "..") == 0)
    return 0;

  return 1;
}

void showErrorAndExit() {
  printf("Invalid directory...\n");
  exit(EXIT_FAILURE);
}

void listDirectory(char const *dirName, int depth) {
  chdir(dirName);
  DIR *directory = opendir(".");

  if (!directory) {
    showErrorAndExit();
  }

  printFile(dirName, depth);

  struct dirent *entry = readdir(directory);

  while (entry != NULL) {
    struct stat buffer;
    int status;
    status = lstat(entry->d_name, &buffer);

    if (isValid(entry->d_name)) {
      if (status == 0 && S_ISDIR(buffer.st_mode)) {
        listDirectory(entry->d_name, depth + 1);
      } else {
        printFile(entry->d_name, depth);
      }
    }

    entry = readdir(directory);
  }

  closedir(directory);
  chdir("..");
}

void treeF(char const *dirName) { listDirectory(dirName, 0); }

int main(int argc, char **argv) {
  if (argc < 2) {
    showErrorAndExit();
  }

  treeF(argv[1]);
  exit(EXIT_SUCCESS);
}

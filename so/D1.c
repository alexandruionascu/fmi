#include<dirent.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int isValidDirectory(char const* dirName) {
  if(strcmp(dirName, ".") == 0 )
    return 0;

  if(strcmp(dirName, "..") == 0)
    return 0;

  DIR* directory = opendir(dirName);
  if(!directory)
    return 0;

  return 1;
}

void showErrorAndExit() {
  printf("Error reading the directory...\n");
  exit(EXIT_FAILURE);
}

void listDirectory(char const* dirName) {
  DIR* directory = opendir(dirName);
  if(!directory) {
    showErrorAndExit();
  }

  struct dirent* entry = readdir(directory);

  while(entry != NULL) {
    if(entry->d_type == DT_DIR) {
      if(isValidDirectory(entry->d_name)) {
        printf("DIR %s \n", entry->d_name);
        listDirectory(entry->d_name);
      }
    } else {
      printf("FILE %s \n", entry->d_name);
    }

    entry = readdir(directory);
  }

}

int main(int argc, char** argv) {
  if(argc < 2) {
    showErrorAndExit();
  }

  listDirectory(argv[1]);

  return 0;
}

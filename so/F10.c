#include <stdio.h>
#include <stdlib.h>


void appendToFile(char* fileName, FILE* destinationFile) {
  FILE* file = fopen(fileName,"r");


  if(file == NULL) {
    perror("Error ");
    printf("Press any key to exit...\n");
    exit(EXIT_FAILURE);
  }

  if(destinationFile == NULL ) {
     perror("Error ");
     printf("Press any key to exit...\n");
     exit(EXIT_FAILURE);
  }

  char c;
  while((c = fgetc(file)) != EOF )
     fputc(c, destinationFile);
}

int main(int argc, char** argv) {
   int i = 1;
   char* destination = argv[argc - 1];
   FILE* destinationFile = fopen(destination, "w");

   if(destinationFile == NULL) {
     perror("Error ");
     printf("Press any key to exit...\n");
     exit(EXIT_FAILURE);
   }

   for(i = 1; i < argc - 1; i++) {
     printf("%s -> %s\n", argv[i], destination);
     appendToFile(argv[i], destinationFile);
   }

   return 0;
}

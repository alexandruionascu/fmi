#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {

   if(argc < 2) {
      printf("No argument privded \n");
      exit(EXIT_FAILURE);
   }

   FILE* textFile = fopen(argv[1], "r");
   FILE* binaryFile = fopen("doc2.txt", "wb");

   if(textFile == NULL || binaryFile == NULL) {
     perror("Error openning the file...\n");
     exit(EXIT_FAILURE);
   }

   char buffer;
   int number;

   while (!feof(textFile)) {
     fread(&buffer, sizeof(char), 1, textFile);
     number = buffer;
     printf("%c", buffer);
     fwrite(&number, sizeof(int), 1, binaryFile);
   }


   return 0;
}

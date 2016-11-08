#include<stdio.h>
#include<stdlib.h>

int main(int argc, char** argv) {
  if(argc < 2) {
    printf("No argument provided \n");
  } else {
    int number = atoi(argv[1]);
    int i = 2;
    int isPrime = 1;
    while(i * i <= number) {
      if(number % i == 0) {
        isPrime = 0;
      }
      i++;
    }

    if(number <= 1 || isPrime == 0)
      printf("Number %d is not prime. \n", number);
    else
      printf("Number %d is prime. \n", number);
  }

  return 0;
}

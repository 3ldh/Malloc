#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
//#include "lib_malloc.h"

int main()
{
  //  void *ptr = malloc(12);
  //printf("Addr = %p\n", ptr);
  char c[1];
  
  printf("%d\n", sizeof(void*));
  printf("%d\n", sizeof(char));
  printf("size %d\n", sizeof(size_t));
  printf("%d\n", sizeof(bool));
  printf("%d\n", sizeof(int));
  printf("%d\n", sizeof(c));
}

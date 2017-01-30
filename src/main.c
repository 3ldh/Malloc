#include <stdio.h>
#include <unistd.h>
#include "lib_malloc.h"

int main()
{
  char c[1];
  void *ptr = malloc(105);
  show_alloc_mem();
  //free(ptr);
  //free(c);
  ptr = malloc(4097);
  show_alloc_mem();
  //free(ptr);
  //ptr = malloc(4097);
  void *ptr1 = malloc(180);
  void *ptr2 = malloc(105);
  void *ptr3 = malloc(110);
  void *ptr4 = malloc(120);
  show_alloc_mem();
}

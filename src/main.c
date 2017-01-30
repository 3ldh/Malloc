#include <stdio.h>
#include <unistd.h>
#include "lib_malloc.h"

int main()
{
  char c[1];
  /* void *ptr = malloc(105); */
  /* show_alloc_mem(); */
  /* free(ptr); */
  //free(c);
  //  ptr = malloc(4097);
  //  show_alloc_mem();
  //free(ptr);
  //ptr = malloc(4097);
  void *ptr1 = malloc(1056);
  void *ptr2 = malloc(1000);
  // void *ptr3 = malloc(1000);
  //  void *ptr4 = malloc(500);
  show_alloc_mem();

  free(ptr1);
  free(ptr2);
  //  free(ptr3);
  //  free(ptr4);
  //ptr1 = malloc(1000);
  show_alloc_mem();
}

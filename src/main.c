#include <stdio.h>
#include <unistd.h>
#include "lib_malloc.h"

int main()
{
  /* char *ptr = malloc(5); */

  /* strcpy(ptr, "toto\0");   */
  /* show_alloc_mem(); */
  /* write(1, ptr, strlen(ptr)); */
  /* write(1, "\n", 1); */
  /* ptr = realloc(ptr, 10); */
  /* show_alloc_mem(); */
  /* write(1, ptr, strlen(ptr)); */
  /* write(1, "\n", 1); */

  void *ptr = malloc(1);
  void *ptr1 = malloc(2);
  void *ptr2 = malloc(2);
  void *ptr3 = malloc(2);
  void *ptr4 = malloc(2);
  show_alloc_mem();
  free(ptr1);
  free(ptr2);

  free(ptr4);
  free(ptr3);
  realloc(ptr1, 0);
  show_alloc_mem();
}

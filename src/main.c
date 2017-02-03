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

  void *ptr1 = malloc(5000);
  void *ptr2 = malloc(20000);
  show_alloc_mem();
  free(ptr1);
  free(ptr2);
  show_alloc_mem();
}

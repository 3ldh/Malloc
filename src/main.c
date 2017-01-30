#include <stdio.h>
#include <unistd.h>
#include "lib_malloc.h"

int main()
{
  void *ptr = malloc(105);
  show_alloc_mem();

  /* free(ptr); */
  /* ptr = malloc(105); */
  /* show_alloc_mem(); */
}

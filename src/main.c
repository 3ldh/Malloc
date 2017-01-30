#include <stdio.h>
#include <unistd.h>
#include "lib_malloc.h"

int main()
{
  void *ptr = malloc(1050);
  void *ptr2 = malloc(500);
  free(ptr);
  free(ptr2);
  show_alloc_mem();
}

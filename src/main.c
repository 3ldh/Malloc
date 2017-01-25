#include <stdio.h>
#include <unistd.h>

#include "lib_malloc.h"

int main()
{
  void *ptr = malloc(12);
  printf("Addr = %p\n", ptr);
}

#include <stdio.h>
#include <unistd.h>
#include "lib_malloc.h"

int main()
{
  char *ptr = malloc(5);
  strcpy(ptr, "toto\0");
  
  show_alloc_mem();
  write(1, ptr, strlen(ptr));
  write(1, "\n", 1);
  ptr = realloc(ptr, 10);

  show_alloc_mem();
  //printf("%s\n", ptr);
  write(1, ptr, strlen(ptr));
  write(1, "\n", 1);
}

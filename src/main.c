#include <stdio.h>
#include <unistd.h>

int main()
{
  void *ptr;

  int i = 0;
  while (i++ < 20)
    {
      ptr = sbrk(20);
      printf("%p\n", ptr);
    }
  printf("%p\n", ptr + 20);
  return (0);
}

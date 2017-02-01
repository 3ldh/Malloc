#include <stdio.h>
#include <unistd.h>
#include "lib_malloc.h"

int main()
{
    show_alloc_mem();
    void *ptr = malloc(100);
    free(ptr);
    free(ptr);
}

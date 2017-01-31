#include <stdio.h>
#include <unistd.h>
#include "lib_malloc.h"

int main()
{
    void *ptr = malloc(12);
    ptr = realloc(ptr, 13);
    show_alloc_mem();
}

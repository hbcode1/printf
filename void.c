#include "main.h"

void print_addr(void *addr)
{
    char const *str = (char const *)addr;
    printf("%s", str);
}
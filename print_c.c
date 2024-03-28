#include "ft_printf.h"

int print_c(int c)
{
    char ch;

    ch = c;
    write(1, &ch, 1);
    return (1);
}

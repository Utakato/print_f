#include "ft_printf.h"

int print_p(void *ptr)
{
    unsigned long num;

    

    num = (unsigned long)ptr;
    if (num == 0)
    {
        write(1, "0x0", 3);
        return (3);
    }
    else
    {
        write(1, "0x", 2);
        return (2 + print_x(num, "0123456789abcdef"));
    }

}
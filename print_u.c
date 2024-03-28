#include "ft_printf.h"

int ft_numlen_u(unsigned int n);
unsigned int rise_to_power_u(unsigned int base, int power);

// void ft_putchar_fd(char c, int fd){
//     const char *c_ptr;
//     c_ptr = (const char *)&c;
//     write(fd, c_ptr, 1);
// }

int print_u(unsigned int n)
{
    int len;
    int original_len;
    len = ft_numlen_u(n);
    original_len = len;
    while (len > 0)
    {   
        len--;
        ft_putchar_fd(((n / rise_to_power_u(10, len)) + '0'), 1);
        n = n % rise_to_power_u(10, len);
    }
    return original_len;
}

int ft_numlen_u(unsigned int n)
{
    int len;
    len = 0;
    if (n == 0)
        return (1);
    while (n > 0)
    {
        n = n / 10;
        len++;
    }
    return (len);
}

unsigned int rise_to_power_u(unsigned int base, int power)
{
    unsigned int result;
    result = 1;
    while (power > 0)
    {
        result = result * base;
        power--;
    }
    return (result);
}

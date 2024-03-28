#include "ft_printf.h"

// #include <unistd.h>
// #include <stdio.h>
// #include <limits.h>

// void ft_putchar_fd(char c, int fd){
//     const char *c_ptr;
//     c_ptr = (const char *)&c;
//     write(fd, c_ptr, 1);
// }

int ft_numleya(unsigned int n, int base_length)
{
    int len;
    len = 0;

    if (n == 0)
        return (1);
    while (n > 0)
    {
        n = n / base_length;
        len++;
    }
    return (len);
}


unsigned int rise_to_power_ua(unsigned int base, int power)
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



int print_x( int n,char *base)
{
    int len;
    int i;
    unsigned int u_n;
    int base_length;

    i = 0;
    u_n = n;
    base_length = 16;//replace with ft_strlen(base)
    len = ft_numleya(u_n, base_length);

    // printf("n = %d\n", n);
    // printf("u_n = %d\n", u_n);
    // printf("len = %d\n", len);
    while (len > 0)
    {   
        len--;
        ft_putchar_fd(base[(u_n / rise_to_power_ua(16, len))], 1);
        u_n = u_n % rise_to_power_ua(16, len);
        i++;
    }
    return (i);
}


// int main ()
// {
//     int original = 0;
//     int mine = 0;

//     int n = -1;
//     original = printf("%x", n);
//     printf("\n");
//     printf("Original: %d\n", original);

//     mine = print_x(n, "0123456789abcdef");
//     printf("\n");
//     printf("Mine: %d\n", mine);
//     return (0);
// }
// 32:     TEST(8, print(" %x ", 16));
// 33:     TEST(9, print(" %x ", 17));
// 34:     TEST(10, print(" %x ", 99));
// 46:     TEST(22, print(" %x ", INT_MAX));
// 53:     TEST(29, print(" %x %x %x %x %x %x %x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
// 54:     TEST(30, print(" %x ", 42));
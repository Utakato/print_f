#include "ft_printf.h"

int handle_flags(char flag, va_list *args);
int print_next(const char *str, int *i, va_list *args);
int    ft_printf(const char *str, ...);

int handle_flags(char flag, va_list *args)
{   
    if (flag == 'c')
    {   
        return print_c(va_arg(*args, int));
    } else if (flag == 's')
    {
        return print_s(va_arg(*args, char *));
    } else if (flag == '%')
    {
        write(1, "%", 1);
        return (1);
    } else if (flag == 'i' || flag == 'd')
    {
        return print_d(va_arg(*args, int));
    } else if (flag == 'u')
    {
        return print_u(va_arg(*args, unsigned int));
    } 
    else if (flag == 'x')
    {
        return print_x(va_arg(*args, unsigned int), "0123456789abcdef");
    } else if (flag == 'X')
    {
        return print_x(va_arg(*args, unsigned int), "0123456789ABCDEF");
    } else if (flag == 'p')
    {
        return print_p(va_arg(*args, void *));
    }

    return (-1);

}

int print_next(const char *str, int *i, va_list *args)
{   
    int printed_chars;

    printed_chars = 0;
    while (str[*i])
    {   
        if (str[*i] == '%')
        {   
            (*i)++;
           return handle_flags(str[*i], args);
        }
        else
        {
            write(1, &str[*i], 1);
            return (1);
        }
        (*i)++;
    }
    return (printed_chars);
}


// figure out a way to test this
int    ft_printf(const char *str, ...)
{
    va_list args;
    int i;
    int printed_chars;

    i = 0;
    printed_chars = 0;
    va_start(args, str);
    while (str[i])
    {
        printed_chars += print_next(str, &i, &args);
        i++;
    }

    va_end(args);
    return (printed_chars);
}

// int main ()
// {   
//     int original = 0;
//     int mine = 0;
//     original = printf(" %u ", 1231251);
//     printf("Original: %d\n", original);

//     mine = ft_printf(" %u ", 1231251);

//     printf("Mine: %d\n", mine);
//     return (0);
// }




// %p The void * pointer argument has to be printed in hexadecimal format. %d Prints a decimal (base 10) number.

// %u Prints an unsigned decimal (base 10) number.
// %x Prints a number in hexadecimal (base 16) lowercase format.
// %X Prints a number in hexadecimal (base 16) uppercase format.

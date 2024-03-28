#include "ft_printf.h"

int print_s(char * str)
{
    int i;

    i = 0;
    if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	i = 0;
    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
    return (i);
}

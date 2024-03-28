#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int print_c(int c);
int print_d(int n);
int print_s(char * str);
int print_u(unsigned int n);
int print_x(int n,char *base);
int print_p(void *ptr);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschipor <fschipor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 19:36:24 by fschipor          #+#    #+#             */
/*   Updated: 2024/03/28 22:34:02 by fschipor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_flags(char flag, va_list *args);
int	print_next(const char *str, int *i, va_list *args);
int	ft_printf(const char *str, ...);

int	handle_flags(char flag, va_list *args)
{
	if (flag == 'c')
		return (print_c(va_arg(*args, int)));
	else if (flag == 's')
		return (print_s(va_arg(*args, char *)));
	else if (flag == 'i' || flag == 'd')
		return (print_d(va_arg(*args, int)));
	else if (flag == 'u')
		return (print_u(va_arg(*args, unsigned int)));
	else if (flag == 'x')
		return (print_x(va_arg(*args, unsigned long int), "0123456789abcdef"));
	else if (flag == 'X')
		return (print_x(va_arg(*args, unsigned long int), "0123456789ABCDEF"));
	else if (flag == 'p')
		return (print_p(va_arg(*args, unsigned long long *)));
	else if (flag == '%')
	{
		return write(1, "%", 1);
	}
	return (-1);
}

int	print_next(const char *str, int *i, va_list *args)
{
	int	printed_chars;

	printed_chars = 0;
	while (str[*i])
	{
		if (str[*i] == '%')
		{
			(*i)++;
			return (handle_flags(str[*i], args));
		}
		else
			return (write(1, &str[*i], 1));
		(*i)++;
	}
	return (printed_chars);
}


int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		printed_chars;

	i = 0;
	printed_chars = 0;
	va_start(args, str);
	while (str[i])
	{
		printed_chars += print_next(str, &i, &args);
		if (printed_chars < 0)
			return (-1);
		i++;
	}
	va_end(args);
	return (printed_chars);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschipor <fschipor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 19:38:43 by fschipor          #+#    #+#             */
/*   Updated: 2024/03/28 22:22:03 by fschipor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex(unsigned long long n, char *base);

int	print_p(unsigned long long *ptr)
{
	unsigned long long	num;

	num = (unsigned long long)ptr;
	if (num == 0)
	{
		write(1, "0x0", 3);
		return (3);
	}
	else
	{
		write(1, "0x", 2);
		return (2 + print_hex(num, "0123456789abcdef"));
	}
}



int	ft_num_len_ull(unsigned long long n, int base_length)
{
	int	len;

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

unsigned long long	rise_to_power_ull(unsigned int base, int power)
{
	unsigned long long	result;

	result = 1;
	while (power > 0)
	{
		result = result * base;
		power--;
	}
	return (result);
}

int	print_hex(unsigned long long n, char *base)
{
	int	len;
	int	i;
	int	base_length;

	i = 0;
	base_length = 16;
	len = ft_num_len_ull(n, base_length);
	while (len > 0)
	{
		len--;
		ft_putchar_fd(base[(n / rise_to_power_ull(16, len))], 1);
		n = n % rise_to_power_ull(16, len);
		i++;
	}
	return (i);
}

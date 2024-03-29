/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschipor <fschipor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 19:40:31 by fschipor          #+#    #+#             */
/*   Updated: 2024/03/28 21:50:52 by fschipor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_numleya(unsigned long n, int base_length)
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

unsigned int	rise_to_power_int(unsigned int base, int power)
{
	unsigned int	result;

	result = 1;
	while (power > 0)
	{
		result = result * base;
		power--;
	}
	return (result);
}

int	print_x(unsigned int n, char *base)
{
	int	len;
	int	i;
	int	base_length;

	i = 0;
	base_length = 16;
	len = ft_numleya(n, base_length);
	while (len > 0)
	{
		len--;
		ft_putchar_fd(base[(n / rise_to_power_int(16, len))], 1);
		n = n % rise_to_power_int(16, len);
		i++;
	}
	return (i);
}

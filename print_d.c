/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschipor <fschipor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 19:38:26 by fschipor          #+#    #+#             */
/*   Updated: 2024/03/28 19:38:38 by fschipor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_numlennn(int n);

int	print_d(int n)
{
	int	len;

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	ft_putnbr_fd(n, 1);
	len = ft_numlennn(n);
	return (len);
}

int	ft_numlennn(int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		n = n * -1;
		len++;
	}
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

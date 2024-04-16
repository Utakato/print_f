/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschipor <fschipor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 21:19:08 by fschipor          #+#    #+#             */
/*   Updated: 2024/03/27 21:24:50 by fschipor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_numlenn(int n);
int		rise_to_powerr(int base, int power);

void	ft_putnbr_fd(int n, int fd)
{
	int	len;

	len = ft_numlenn(n);
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = n * -1;
		len--;
	}
	while (len > 0)
	{
		len--;
		ft_putchar_fd(((n / rise_to_powerr(10, len)) + '0'), fd);
		n = n % rise_to_powerr(10, len);
	}
}

int	ft_numlenn(int n)
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

int	rise_to_powerr(int base, int power)
{
	int	result;

	result = 1;
	while (power > 0)
	{
		result = result * base;
		power--;
	}
	return (result);
}

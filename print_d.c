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

static int rise_to_powerr(int base, int power);
static int ft_numlenn(int n);
static int rise_to_powerr(int base, int power);
static int ft_putnbr(int n);

int	print_d(int n)
{
	int	len;

	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (ft_putnbr(n) == -1)
		return (-1);
	len = ft_numlenn(n);
	return (len);
}




static int ft_putnbr(int n)
{
    int len;

    len = ft_numlenn(n);
    if (n == -2147483648)
    {
        return (write(1, "-2147483648", 11));
    }
    if (n < 0)
    {
        if (write(1,"-", 1) == -1)
			return (-1);
        n = n * -1;
  
        len--;
    }
     while (len > 0)
    {   
        len--;
        if (print_c(((n / rise_to_powerr(10, len)) + '0')) == -1)
			return (-1);
        n = n % rise_to_powerr(10, len);
    }
	return (0);
}

static int ft_numlenn(int n)
{
    int len;
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

static int rise_to_powerr(int base, int power)
{
    int result;
    result = 1;
    while (power > 0)
    {
        result = result * base;
        power--;
    }
    return (result);
}

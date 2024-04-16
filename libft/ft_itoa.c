/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschipor <fschipor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 21:17:45 by fschipor          #+#    #+#             */
/*   Updated: 2024/03/27 21:40:39 by fschipor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_numlen(int n);
int		rise_to_power(int base, int power);
void	handle_negative(int *n, char *str, int *i, int *len);

char	*ft_itoa(int n)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	len = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_numlen(n);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	handle_negative(&n, str, &i, &len);
	while (len-- > 0)
	{
		str[i] = (n / rise_to_power(10, len)) + '0';
		n = n % rise_to_power(10, len);
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	handle_negative(int *n, char *str, int *i, int *len)
{
	if (*n < 0)
	{
		str[*i] = '-';
		*n = *n * -1;
		*i = *i + 1;
		*len = *len - 1;
	}
}

int	ft_numlen(int n)
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

int	rise_to_power(int base, int power)
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

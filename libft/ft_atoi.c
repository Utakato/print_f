/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschipor <fschipor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:54:56 by fschipor          #+#    #+#             */
/*   Updated: 2024/03/27 22:05:50 by fschipor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		res;
	int		sign;
	int		i;
	char	*cp;

	cp = ft_strtrim(str, "\t\n\r\v\f ");
	res = 0;
	sign = 1;
	i = 0;
	if (cp[0] == '-')
	{
		sign = -1;
		i++;
	}
	if (cp[0] == '+')
	{
		sign = 1;
		i++;
	}
	while (cp[i] != '\0' && ft_isdigit(cp[i]))
	{
		res = res * 10 + cp[i] - '0';
		i++;
	}
	return (free(cp), (sign * res));
}

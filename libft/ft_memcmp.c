/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschipor <fschipor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:24:30 by fschipor          #+#    #+#             */
/*   Updated: 2024/03/27 21:17:53 by fschipor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_c;
	unsigned char	*s2_c;

	s1_c = (unsigned char *)s1;
	s2_c = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (s1_c[i] == s2_c[i] && i < n - 1)
	{
		i++;
	}
	return (s1_c[i] - s2_c[i]);
}

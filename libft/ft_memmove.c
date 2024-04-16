/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschipor <fschipor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 10:30:58 by fschipor          #+#    #+#             */
/*   Updated: 2024/03/27 21:27:52 by fschipor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	unsigned char		*p1;
	const unsigned char	*p2;
	size_t				i;

	p1 = (unsigned char *)s1;
	p2 = (const unsigned char *)s2;
	i = 0;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (p2 < p1)
	{
		while (n-- > 0)
			p1[n] = p2[n];
	}
	else
	{
		while (i < n)
		{
			p1[i] = p2[i];
			i++;
		}
	}
	return (s1);
}

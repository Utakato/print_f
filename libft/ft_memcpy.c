/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschipor <fschipor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 10:30:51 by fschipor          #+#    #+#             */
/*   Updated: 2024/03/30 19:50:33 by fschipor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	unsigned char		*p1;
	const unsigned char	*p2;
	size_t				i;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	p1 = (unsigned char *)s1;
	p2 = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		p1[i] = p2[i];
		i++;
	}
	return (s1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschipor <fschipor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:08:08 by fschipor          #+#    #+#             */
/*   Updated: 2024/03/27 21:20:06 by fschipor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	res;

	i = 0;
	while (dst[i] != '\0' && i < dstsize)
		i++;
	res = ft_strlcpy(dst + i, src, dstsize - i);
	return (res + i);
}

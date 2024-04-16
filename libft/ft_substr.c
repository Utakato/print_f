/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschipor <fschipor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:50:40 by fschipor          #+#    #+#             */
/*   Updated: 2024/03/27 21:21:22 by fschipor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*small_str;

	if (start > (size_t)ft_strlen(s))
		return (ft_strdup(""));
	if (len > (size_t)ft_strlen(s + start))
		len = (size_t)ft_strlen(s + start);
	small_str = (char *)malloc((len + 1) * sizeof(char));
	if (small_str == NULL)
		return (NULL);
	ft_strlcpy(small_str, s + start, len + 1);
	return (small_str);
}

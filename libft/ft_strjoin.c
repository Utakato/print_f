/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschipor <fschipor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:52:28 by fschipor          #+#    #+#             */
/*   Updated: 2024/03/08 17:36:21 by fschipor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		s1_len;
	int		s2_len;
	int		total_len;
	char	*joined_str;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	total_len = s1_len + s2_len;
	joined_str = (char *)malloc((total_len + 1) * sizeof(char));
	if (joined_str == NULL)
		return (NULL);
	ft_memcpy(joined_str, s1, s1_len);
	ft_memcpy(&joined_str[s1_len], s2, s2_len);
	joined_str[total_len] = '\0';
	return (joined_str);
}

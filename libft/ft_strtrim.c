/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschipor <fschipor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:51:16 by fschipor          #+#    #+#             */
/*   Updated: 2024/03/27 21:21:54 by fschipor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		get_end_index(const char *set, const char *s1);
int		get_start_index(const char *set, const char *s1);
int		is_matching(const char *set, const char *s1);

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start_index;
	int		end_index;
	int		new_len;
	char	*trimmed_str;

	start_index = get_start_index(set, s1);
	end_index = get_end_index(set, s1);
	new_len = end_index - start_index + 1;
	if (new_len < 1)
	{
		trimmed_str = (char *)malloc((1) * sizeof(char));
		if (trimmed_str == NULL)
			return (NULL);
		trimmed_str[0] = '\0';
		return (trimmed_str);
	}
	trimmed_str = (char *)malloc((new_len + 1) * sizeof(char));
	if (trimmed_str == NULL)
		return (NULL);
	ft_memcpy(trimmed_str, &s1[start_index], new_len);
	trimmed_str[new_len] = '\0';
	return (trimmed_str);
}

int	get_start_index(const char *set, const char *s1)
{
	int	i;
	int	s1_len;

	s1_len = ft_strlen(s1);
	i = 0;
	while (i < s1_len)
	{
		if (is_matching(set, &s1[i]) == 0)
			break ;
		i++;
	}
	return (i);
}

int	is_matching(const char *set, const char *s1)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(set);
	while (i < len)
	{
		if (ft_strncmp(s1, &set[i], 1) == 0)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int	get_end_index(const char *set, const char *s1)
{
	int	s1_len;

	s1_len = ft_strlen(s1) - 1;
	while (s1_len >= 0)
	{
		if (is_matching(set, &s1[s1_len]) == 1)
			s1_len--;
		else
			break ;
	}
	return (s1_len);
}

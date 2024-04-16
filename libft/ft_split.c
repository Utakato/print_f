/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschipor <fschipor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:53:53 by fschipor          #+#    #+#             */
/*   Updated: 2024/03/30 19:54:06 by fschipor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*get_string_position(char *str, char del, int start_index,
			int *positions);
int		get_str_c(char *str, char delimiter);
void	free_everything(char **results, int i);

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		last_index;
	int		positions[2];
	int		i;

	i = 0;
	last_index = 0;
	result = (char **)malloc((get_str_c((char *)s, c) + 1) * sizeof(char *));
	if (result == NULL)
		return (NULL);
	while (i < get_str_c((char *)s, c))
	{
		get_string_position((char *)s, c, last_index, positions);
		result[i] = ft_substr(s, positions[0], positions[1] - positions[0]);
		if (result[i] == NULL)
			return (free_everything(result, i), (NULL));
		last_index = positions[1];
		i++;
	}
	result[i] = NULL;
	return (result);
}

int	*get_string_position(char *str, char del, int start_index, int *positions)
{
	int	end_index;
	int	i;

	end_index = start_index;
	i = start_index;
	while (str[i] != '\0')
	{
		if (str[i] == del)
		{
			if (str[i + 1] == del && i++)
				continue ;
			start_index = i + 1;
		}
		if (str[i] != del && (str[i + 1] == del || str[i + 1] == '\0'))
		{
			end_index = i + 1;
			break ;
		}
		i++;
	}
	positions[0] = start_index;
	positions[1] = end_index;
	return (positions);
}

int	get_str_c(char *str, char delimiter)
{
	int	i;
	int	str_count;

	i = 0;
	str_count = 0;
	while (str[i] != '\0')
	{
		if (str[i] != delimiter && (str[i + 1] == delimiter || str[i
					+ 1] == '\0'))
		{
			str_count++;
		}
		i++;
	}
	return (str_count);
}

void	free_everything(char **results, int i)
{
	while (i >= 0)
	{
		if (results[i] != NULL)
			free(results[i]);
		i--;
	}
	if (results != NULL)
		free(results);
}

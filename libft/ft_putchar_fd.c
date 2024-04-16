/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschipor <fschipor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 21:18:09 by fschipor          #+#    #+#             */
/*   Updated: 2024/03/27 21:35:09 by fschipor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	const char	*c_ptr;

	c_ptr = (const char *)&c;
	write(fd, c_ptr, 1);
}

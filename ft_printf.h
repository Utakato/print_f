/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschipor <fschipor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 19:40:58 by fschipor          #+#    #+#             */
/*   Updated: 2024/04/16 19:58:28 by fschipor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	print_c(int c);
int	print_d(int n);
int	print_s(char *str);
int	print_u(unsigned int n);
int	print_x(unsigned int n, char *base);
int	print_p(unsigned long long *ptr);

#endif
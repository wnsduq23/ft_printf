/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:35:58 by junykim           #+#    #+#             */
/*   Updated: 2022/04/24 11:24:20 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_putstr_fd_len(char *s, int fd, size_t len)
{
	size_t	i;

	if (!s)
		return ;
	i = 0;
	while (s[i] && i < len)
		ft_putchar_fd(s[i++], fd);
}

size_t	ft_putstr(char *fmt)
{
	char	*from;
	
	from = fmt;
	while (is_alpha(*fmt))
		fmt++;
	ft_putstr_fd_len(from, STDOUT, fmt - from);
	return (fmt - from);
}

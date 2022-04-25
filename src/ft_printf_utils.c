/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:35:58 by junykim           #+#    #+#             */
/*   Updated: 2022/04/25 20:52:37 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/ft_printf.h"

size_t	ft_putstr(const char *s, t_tag *tag)
{
	const char	*from;

	if (s == 0)
	{
		write (STDOUT, "(null)", 6);
		tag->cnt += 6;
		return (0);
	}
	from = s;
	while (*s != '%' && *s != 0)
		s++;
	write(STDOUT, from, s - from);
	tag->cnt += s - from;
	return (s - from);
}

void	ft_putnbr_int(int n, t_tag *tag)
{
	if (n == -2147483648)
	{
		ft_putnbr_int(-214748364, tag);
		ft_putchar_int('8', tag);
	}
	else if (n < 0)
	{
		ft_putchar_int('-', tag);
		ft_putnbr_int(-n, tag);
	}
	else
	{
		if (n >= 10)
			ft_putnbr_int(n / 10, tag);
		ft_putchar_int(n % 10 + '0', tag);
	}
}

void	ft_putchar_int(char c, t_tag *tag)
{
	write(STDOUT, &c, 1);
	tag->cnt += 1;
}

void	ft_putnbr_uint(unsigned int n, t_tag *tag)
{
	if (n >= 10)
		ft_putnbr_uint(n / 10, tag);
	ft_putchar_int(n % 10 + '0', tag);
}

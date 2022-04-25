/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_m.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 09:43:47 by junykim           #+#    #+#             */
/*   Updated: 2022/04/25 17:30:15 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

/** TODO	1) if fail read_tag, then return what? */
/**         2) */
static int	parsing_specifier(va_list argp, const char *fmt, t_tag *tag)
{
	if (*fmt == 'c')
		ft_putchar_int(va_arg(argp, int), tag);
	else if (*fmt == 's')
		ft_putstr(va_arg(argp, char *), tag);
	else if (*fmt == 'p')
		ft_print_hex_malloc(va_arg(argp, unsigned long long), 2, tag);
	else if (*fmt == 'd' || *fmt == 'i')
		ft_putnbr_int(va_arg(argp, int), tag);
	else if (*fmt == 'u')
		ft_putnbr_uint(va_arg(argp, unsigned int), tag);
	else if (*fmt == 'x')
		ft_print_hex_malloc(va_arg(argp, unsigned int), 1, tag);
	else if (*fmt == 'X')
		ft_print_hex_malloc(va_arg(argp, unsigned int), 0, tag);
	else if (*fmt == '%')
		ft_putchar_int('%', tag);
	else
		return (0);
	return (1);
}

static int	read_tag(va_list argp, const char *fmt)
{
	t_tag	tag;

	ft_memset(&tag, 0, sizeof(t_tag));
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			if (parsing_specifier(argp, fmt, &tag) == 0)
				return (-1);
		}
		else
			fmt += ft_putstr(fmt, &tag) - 1;
		fmt++;
	}
	return (tag.cnt);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	argptr;
	int		cnt;

	va_start(argptr, fmt);
	cnt = read_tag(argptr, fmt);
	va_end(argptr);
	return (cnt);
}

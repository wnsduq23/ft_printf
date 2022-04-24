/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_m.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 09:43:47 by junykim           #+#    #+#             */
/*   Updated: 2022/04/24 20:00:58 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	parsing_specifier_and_print(va_list argp, const char *fmt, t_tag *tag)
{
	if (*fmt == 'c')
		tag->cnt += ft_putchar_int(va_arg(argp, int));
	else if (*fmt == 's')
		tag->cnt += ft_putstr(va_arg(argp, char *));
	else if (*fmt  == 'p')
		ft_print_hex_fit(va_arg(argp, unsigned long long), 1);
	else if (*fmt == 'd' || *fmt == 'i')
		ft_putstr_fd(ft_itoa(va_arg(argp, int)), STDOUT);
	else if (*fmt == 'u')
		ft_putnbr_fd(va_arg(argp, unsigned int), STDOUT);
	else if (*fmt == 'x')
		ft_print_hex_fit(va_arg(argp, unsigned int), 1);
	else if (*fmt == 'X')
		ft_print_hex_fit(va_arg(argp, unsigned int), 0);
	else if (*fmt == '%')
		ft_putchar_fd('%', STDOUT);
	else 
		return (0);// FAIL
	return (tag->cnt);// SUCCESS
}
//ex. abcd %d %c efg %s
static int	read_tag(va_list argp, const char *fmt)
{
	t_tag	tag;

	ft_memset(&tag, 0, sizeof(t_tag));
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			if (parsing_specifier_and_print(argp, fmt, &tag) == 0)
				return (-1); // FAIL
		}
		else
		{
			/** tag.cnt += ft_putstr(fmt); */
			fmt += ft_putstr(fmt) - 1;
		}
		fmt++;
	}
	return (tag.cnt);//SUCCESS
}

int	ft_printf(const char *fmt, ...)
{
	va_list	argptr;
	int		cnt;

	va_start(argptr, fmt);
	cnt = read_tag(argptr, fmt);//1 : SUCCESS , 0 : FAIL
	va_end(argptr);
	return (cnt); // 반환값 overflow도 신경써줘야하나?
}

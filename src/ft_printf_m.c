/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_m.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 09:43:47 by junykim           #+#    #+#             */
/*   Updated: 2022/04/24 12:06:02 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	parsing_specifier_and_print(va_list argp, const char *fmt)
{
	if (*fmt == 'c')
		ft_putchar_fd(va_arg(argp, int), STDOUT);
	else if (*fmt == 's')
		ft_putstr_fd(va_arg(argp, char *), STDOUT);
	else if (*fmt  == 'p')
		ft_print_address(va_arg(argp, ));
	else if (*fmt == 'd' || *fmt == 'i')
		ft_atoi(va_arg(argp, int));
	else if (*fmt == 'u')
		ft_unsigned_atoi();
	else if (*fmt == 'x')
		ft_atoi_base(fmt, "0123456789abcdef");
	else if (*fmt == 'X')
		ft_atoi_base(fmt, "0123456789ABCDEF");
	else if (*fmt == '%')
		ft_putchar_fd('%', STDOUT);
	else 
		return (0);// FAIL
	return (1);// SUCCESS
}

static int	is_separator(const char *fmt)
{
	if (*fmt == '%' && ft_isalpha(*fmt))
		return (1);
	else if (ft_isalnum(*fmt))
		return (0);
	else
		return (2);
}

//ex. abcd %d %c efg %s
static int	read_tag(va_list argp, const char *fmt)
{
	int		sep;

	while (*fmt)
	{
		sep = is_separator(fmt);
		if (sep == 1)
		{
			fmt++;
			if(!parsing_specifier_and_print(argp, fmt))
				return (0); // FAIL
		}
		else if (sep == 0)
			fmt += ft_putstr(fmt) - 1;
		fmt++;
	}
	return (???);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	argptr;
	int		done;

	va_start(argptr, fmt);
	done = read_tag(argptr, fmt);
	va_end(argptr);
	return (done); // 반환값 overflow도 신경써줘야하나?
}

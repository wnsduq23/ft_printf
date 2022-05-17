/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 17:35:07 by junykim           #+#    #+#             */
/*   Updated: 2022/05/17 22:20:18 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_format_c(va_list argp, t_tag *tag)
{
	ft_putchar_fd(va_arg(argp, int), STDOUT);
	tag->cnt += 1;
}

void	ft_format_s(va_list argp, t_tag *tag)
{
	ft_putstr(va_arg(argp, char *), tag);
}

void	ft_format_p(va_list argp, t_tag *tag)
{
	write(STDOUT, "0x", 2);
	tag->cnt += 2;
	tag->cnt += ft_print_hex_malloc(va_arg(argp, size_t), 1);
}

void	ft_format_d(va_list argp, t_tag *tag)
{
	ft_putnbr_int(va_arg(argp, int), tag);
}

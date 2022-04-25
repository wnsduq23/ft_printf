/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 18:14:44 by junykim           #+#    #+#             */
/*   Updated: 2022/04/25 20:58:30 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_format_i(va_list argp, t_tag *tag)
{
	ft_putnbr_int(va_arg(argp, int), tag);
}

void	ft_format_u(va_list argp, t_tag *tag)
{
	ft_putnbr_uint(va_arg(argp, unsigned int), tag);
}

void	ft_format_x(va_list argp, t_tag *tag)
{
	tag->cnt += ft_print_hex_malloc(va_arg(argp, unsigned int), 1);
}

void	ft_format_upperx(va_list argp, t_tag *tag)
{
	tag->cnt += ft_print_hex_malloc(va_arg(argp, unsigned int), 0);
}

void	ft_format_percent(va_list argp, t_tag *tag)
{
	(void)argp;
	ft_putchar_int('%', tag);
}

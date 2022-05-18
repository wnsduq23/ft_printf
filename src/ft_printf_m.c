/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_m.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 09:43:47 by junykim           #+#    #+#             */
/*   Updated: 2022/05/18 13:55:28 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void	parsing_specifier(va_list argp, const char *fmt, t_tag *tag)
{
	static void	(*fp[9])(va_list argp, t_tag *tag);

	if (fp[8] == NULL)
		link_fp_format(fp);
	(fp[find_specifier_idx(fmt)])(argp, tag);
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
			parsing_specifier(argp, fmt, &tag);
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

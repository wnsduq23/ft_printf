/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 20:23:16 by junykim           #+#    #+#             */
/*   Updated: 2022/04/25 20:38:39 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	find_specifier_idx(const char *fmt)
{
	const char	*specifier;
	int			idx;

	specifier = "cspdiuxX%";
	idx = 0;
	while (specifier[idx] != 0)
	{
		if (specifier[idx] == *fmt)
			return (idx);
		idx++;
	}
	return (-1);
}

void	link_fp_format(void (*fp[])(va_list, t_tag *))
{
	fp[0] = ft_format_c;
	fp[1] = ft_format_s;
	fp[2] = ft_format_p;
	fp[3] = ft_format_d;
	fp[4] = ft_format_i;
	fp[5] = ft_format_u;
	fp[6] = ft_format_x;
	fp[7] = ft_format_upperx;
	fp[8] = ft_format_percent;
}

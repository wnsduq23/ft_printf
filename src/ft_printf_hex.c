/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:40:34 by junykim           #+#    #+#             */
/*   Updated: 2022/04/25 17:27:26 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <stdlib.h>

static size_t	get_len_base(size_t input, int base)
{
	size_t	size;

	if (input == 0)
		return (1);
	size = 0;
	while (input > 0)
	{
		input /= base;
		size++;
	}
	return (size);
}

void	ft_print_hex_malloc(size_t input, int mode, t_tag *tag)
{
	char		*output;
	const char	*hex;
	size_t		i;
	size_t		tmp;

	if (mode == 1)
		hex = "0123456789abcdef";
	else if (mode == 0)
		hex = "0123456789ABCDEF";
	else if (mode == 2)
	{
		hex = "0123456789abcdef";
		write(STDOUT, "0x", 2);
		tag->cnt += 2;
	}
	i = get_len_base(input, 16);
	output = malloc(sizeof(char) * i + 1);
	if (!output)
		return ;
	output[i] = 0;
	tmp = i;
	while (tmp > 0)
	{
		output[tmp-- - 1] = hex[(input % 16)];
		input /= 16;
	}
	write(STDOUT, output, i);
	tag->cnt += i;
	free(output);
}

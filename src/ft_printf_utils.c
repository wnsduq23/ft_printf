/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:35:58 by junykim           #+#    #+#             */
/*   Updated: 2022/04/25 16:05:35 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
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

/** void	ft_print_hex_16(unsigned long long input, int mode) */
/** { */
/**     char		output[17]; */
/**     const char	*hex; */
/**     size_t		i; */
/**  */
/**  */
/**     if (mode)	 */
/**         hex = "0123456789abcdef"; */
/**     else */
/**         hex = "0123456789ABCDEF"; */
/**     i = 16; */
/**     while (i > 0) */
/**     { */
/**         output[i] = hex[input % 16]; */
/**         input /= 16; */
/**         i--; */
/**     } */
/**     output[16] = 0; */
/**     write(STDOUT, output, 16); */
/** } */

static size_t	input_len_16(size_t input)
{
	size_t	size;

	if (input == 0)
		return (1);
	size = 0;
	while (input > 0)
	{
		input /= 16;
		size++;
	}
	return (size);
}
void	ft_print_hex_fit(size_t input, int mode, t_tag *tag)
{
	char		*output;
	const char	*hex;
	size_t		i;
	size_t		tmp;

	if (mode == 1)	
		hex = "0123456789abcdef";
	else if (mode == 0)
		hex = "0123456789ABCDEF";
	else 
	{
		hex = "0123456789abcdef";
		write(STDOUT, "0x", 2);
		tag->cnt += 2;
	}
	i = input_len_16(input);
	output = malloc(sizeof(char) * i + 1);
	if (!output)
		return ;
	output[i] = 0;
	tmp = i;
	while (tmp > 0)
	{
		output[tmp - 1] = hex[(input % 16)];
		input /= 16;
		tmp--;
	}
	write(STDOUT, output, i);
	tag->cnt += i;
	free(output);
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

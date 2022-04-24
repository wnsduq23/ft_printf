/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:35:58 by junykim           #+#    #+#             */
/*   Updated: 2022/04/24 19:27:30 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "../include/ft_printf.h"

size_t	ft_putstr(const char *s)
{
	const char	*from;
	
	if (s == 0)
	{
		write (STDOUT, "(null)", 6);
		return (0);
	}
	from = s;
	while (*s != '%' && *s != 0)
		s++;
	write(STDOUT, from, s - from);
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

static size_t	input_len(size_t input)
{
	if (input == 0)
		return (0);
	else
		return (1 + input_len(input / 10));
}
void	ft_print_hex_fit(size_t input, int mode)
{
	char		*output;
	const char	*hex;
	size_t		i;

	if (mode)	
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	i = input_len(input);
	output = malloc(sizeof(char) * i + 1);
	output[i] = 0;
	if (!output)
		return ;
	while (i > 0)
	{
		output[i] = hex[input % 16];
		input /= 16;
		i--;
	}
	write(STDOUT, output, i);
	free(output);
}

void ft_putnbr_fd_uint(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putnbr_fd(-214748364, fd);
		ft_putchar_fd('8', fd);
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(-n, fd);
	}
	else
	{
		if (n >= 10)
			ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}

}

int	ft_putchar_int(char c)
{
	write(STDOUT, &c, 1);
	return (1);
}

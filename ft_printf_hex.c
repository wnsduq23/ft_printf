/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:40:34 by junykim           #+#    #+#             */
/*   Updated: 2022/04/12 18:24:00 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	is_space(char c)
{
	if ((9 <= c && c <= 13) || c == 32)
		return (1);
	return (0);
}

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*(str + i))
		i++;
	return (i);
}

static int	ft_find_idx(char a, char *base)
{
	int	i;

	i = 0;
	while (*(base + i))
	{
		if (a == *(base + i))
			return (i);
		i++;
	}
	return (-1);
}

static int	Except_check(char *base)
{
	int	len;
	int	i;

	len = 0;
	while (base[len])
	{
		i = len;
		if (base[len] == '+' || base[len] == '-' || \
				is_space(base[len]))
			return (1);
		while (base[++i])
		{
			if (base[len] == base[i])
				return (1);
		}
		len++;
	}
	return (0);
}

int	ft_atoi_base(char *str, char *base)
{
	int	sign;
	int	ans;
	int	idx;
	int	base_len;

	base_len = ft_strlen(base);
	if (Except_check(base) || base_len == 0 || base_len == 1)
		return (0);
	sign = 1;
	ans = 0;
	while (is_space(*str))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
			sign *= -1;
	}
	while (*str)
	{
		idx = ft_find_idx(*str++, base);
		if (idx == -1)
			break ;
		ans = ans * base_len + idx;
	}
	return (sign * ans);
}

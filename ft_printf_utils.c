/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:35:58 by junykim           #+#    #+#             */
/*   Updated: 2022/04/12 18:04:43 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd, size_t len)
{
	size_t	i;

	if (!s)
		return ;
	i = 0;
	while (s[i] && i < len)
		ft_putchar_fd(s[i++], fd);
}

void	ft_print_address()
{

}

int	ft_atoi(const char *str)
{
	int				sign;
	unsigned int	ret;
	size_t			i;

	i = 0;
	while ((9 <= str[i] && str[i] <= 13) || str[i] == 32)
		i++;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	ret = 0;
	while (('0' <= str[i] && str[i] <= '9'))
		ret = ret * 10 + (str[i++] - '0');
	return (ret * sign);
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 13:36:35 by junykim           #+#    #+#             */
/*   Updated: 2022/04/24 19:28:30 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include "libft.h"

typedef struct s_tag
{
	int		cnt;
	char	tag;
}t_tag;
# define STDOUT (1)
int		ft_atoi_base(char *str, char *base);
size_t	ft_putstr(const char *fmt);
void	ft_print_hex_fit(size_t input, int mode);
int	ft_printf(const char *fmt, ...);
size_t	ft_putstr(const char *s);
void	ft_print_hex_16(unsigned long long input, int mode);
void	ft_print_hex_fit(size_t input, int mode);
int	ft_putchar_int(char c);
void ft_putnbr_fd_uint(int n, int fd);
#endif

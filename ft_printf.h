/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 13:36:35 by junykim           #+#    #+#             */
/*   Updated: 2022/04/12 21:02:55 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

typedef enum
{
	STDOUT = 1;
} AAAAAAAAAAAAAA;

typedef struct s_tag
{
	char			*flag;
	unsigned int	width;
	unsigned int	precision;
	char			specifier;
}t_tag;

int		ft_atoi_base(char *str, char *base);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd, size_t len);
int		ft_atoi(const char *str);
#endif

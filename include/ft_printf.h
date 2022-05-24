/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 13:36:35 by junykim           #+#    #+#             */
/*   Updated: 2022/05/24 21:11:14 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct s_tag
{
	int			cnt;
}				t_tag;
# define STDOUT (1)

/*------------------------
	  format_function
------------------------*/
void	ft_format_c(va_list argp, t_tag *tag);
void	ft_format_s(va_list argp, t_tag *tag);
void	ft_format_p(va_list argp, t_tag *tag);
void	ft_format_d(va_list argp, t_tag *tag);
void	ft_format_i(va_list argp, t_tag *tag);
void	ft_format_u(va_list argp, t_tag *tag);
void	ft_format_x(va_list argp, t_tag *tag);
void	ft_format_upperx(va_list argp, t_tag *tag);
void	ft_format_percent(va_list argp, t_tag *tag);

/*------------------------
	ft_pointer_fuction
------------------------*/
int		find_specifier_idx(const char *fmt);
void	link_fp_format(void (*fp[])(va_list, t_tag *));

/*------------------------
	   utils_function
------------------------*/
int		ft_printf(const char *fmt, ...);
size_t	ft_putstr(const char *s, t_tag *tag);
size_t	ft_print_hex_malloc(size_t input, int mode);
void	ft_putchar_int(char c, t_tag *tag);
void	ft_putnbr_uint(unsigned int n, t_tag *tag);
void	ft_putnbr_int(int n, t_tag *tag);

#endif

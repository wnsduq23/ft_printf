/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 13:36:35 by junykim           #+#    #+#             */
/*   Updated: 2022/04/12 16:31:45 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unsitd.h>

typedef struct s_tag
{
	char			flag;
	unsigned int	width;//int?
	unsigned int	precision;
	char			specifier;
}t_tag;
#endif

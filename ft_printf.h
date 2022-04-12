/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 13:36:35 by junykim           #+#    #+#             */
/*   Updated: 2022/04/12 17:32:35 by junykim          ###   ########.fr       */
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
#endif

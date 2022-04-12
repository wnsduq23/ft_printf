/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 13:30:10 by junykim           #+#    #+#             */
/*   Updated: 2022/04/12 16:33:55 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/** va_start 2nd argument? */
/** va_start에서 format 다음 위치를 구한 다음에 argptr에 그 주소값을 넣음 */
/** va_arg에서 2nd 인자에 타입을 넣어서 타입만큼 argptr을 이동시키고 return 타입 사이즈만큼의 값 */
/** format : 문자열 전체를 담아둠. 가변인자는 콤마가 필드구분자로 해서 입력받은 값을 받음 */
/** flag
  *     #	: 0x 출력, ??
  *     ' '	: 앞에 공백 출력
  *     +	: 부호 + or - 출력
  *     0	: 0으로 왼쪽에서부터 출력
  *     .	: 뒤에 오는 숫자만큼 출력
  *     -	: 왼쪽으로 맞춤. 오른쪽은 공백 */
int	ft_printf(const char *format, ...)
{
	va_list	argptr;
	t_tag	a;
	size_t	i;

	va_start(argptr, format);
	i = 0;
	read_tag();
	va_end(argptr);
	return  // 반환값 overflow도 신경써줘야하나?
}

void	read_tag()
{
	/** 형식 태그를 읽어들여서 구조체에 해당하는 값을 집어 넣는다 */
}

void	parsing_specifier(t_tag *p_tag)
{
	if (p_tag->specifier == 'c')
		return ;
	else if (p_tag->specifier == 's')
		;
	else if (p_tag->specifier == 'p')
		;
	else if (p_tag->specifier == 'd')
		;
	else if (p_tag->specifier == 'i')
		;
	else if (p_tag->specifier == 'u')
		;
	else if (p_tag->specifier == 'x')
		;
	else if (p_tag->specifier == 'X')
		;
	else if (p_tag->specifier == '%')
		write(1, "%", 1);
	else 
		return ;
}

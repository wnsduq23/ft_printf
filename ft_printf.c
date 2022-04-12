/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 13:30:10 by junykim           #+#    #+#             */
/*   Updated: 2022/04/12 20:46:32 by junykim          ###   ########.fr       */
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
  *     .	: 뒤에 오는 숫자만큼 출력 - non_flag
  *     -	: 왼쪽으로 맞춤. 오른쪽은 공백 */

static int	is_separator()
{
	/** 문자->숫자 return (1); */
	/** 숫자-> 문자 return (2); */
	/** otherwise return (0); */
}

static void	read_tag(va_list argptr, const char *format)
{
	t_tag	tag;

	memset(&tag,0,sizeof(tag));
	while (*format)
	{
		if (is_separator() == 1)
		{
			char * a = va_arg(argptr, char *);
		}
		else if (is_separator() == 2)
			int a = va_arg(argptr, int);
		else if (is_separator() == 0)
			format++;

	}
	/** 형식 태그를 읽어들여서 구조체에 해당하는 값을 집어 넣는다 */
	/** 어떻게 읽어들일까? 기준이 문자->숫자 or 숫자->문자 로 짜르면 됨  */
}

static void	parsing_specifier(const char **fmt, t_tag *p_tag, size_t len)
{
	/** len 있는 이유 : 폭과 정밀도에 따라 출력해야하는게 달라질 수 있어서 */
	if (p_tag->specifier == 'c')
		ft_putchar_fd(*fmt, STDOUT);
	else if (p_tag->specifier == 's')
		ft_putstr_fd(fmt, STDOUT, len);
	else if (p_tag->specifier == 'p')
		ft_print_address();
	else if (p_tag->specifier == 'd' || p_tag->specifier == 'i')
		ft_atoi();
	else if (p_tag->specifier == 'u')
		ft_unsigned_atoi();
	else if (p_tag->specifier == 'x')
		ft_atoi_base(fmt, "0123456789abcdef");
	else if (p_tag->specifier == 'X')
		ft_atoi_base(fmt, "0123456789ABCDEF");
	else if (p_tag->specifier == '%')
		ft_putchar_fd('%', STDOUT);
	else 
		return ;//이거 어떻게 해야 오류인 걸 알 수 있을까?
}

static void	print_tag(t_tag *p_tag)
{
	/** 각 값이 들어온 것을 write */
	/** width 를 먼저 고려하고,  */
	/** specifier 확인 후에 그 서식의 format len을 보장하고 */
	/** specifier를 확인한다음 s인 경우만 precision 영향가게 하면 될 듯? */
	/** 나머지 남는 사이즈는 flag 확인 해서 해당하는 걸로 채운다 */
	parsing_specifier();
}

int	ft_printf(const char *format, ...)
{
	va_list	argptr;

	va_start(argptr, format);
	read_tag(argptr, format);
	va_end(argptr);
	return ; // 반환값 overflow도 신경써줘야하나?
}

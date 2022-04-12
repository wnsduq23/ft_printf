# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/12 13:39:13 by junykim           #+#    #+#              #
#    Updated: 2022/04/12 18:35:06 by junykim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a
CC = gcc
CFLAG = -Wall -Wextra -Werror
SRCS = ./ft_printf.c \
	   ./ft_printf_hex.c \
	   ./ft_printf_utils.c
INC = .
OBJS = $(SRCS:.c=.o)
DEL = rm -f
ARC = ar -rc

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAG) -c $< -o $@ -I$(INC)

$(NAME) : $(OBJS)
	$(ARC) $@ $(OBJ)

clean :
	$(DEL) $(OBJS)

fclean : clean  
	$(DEL) $(NAME)

re = fclean all

.PHONY : all clean fclean re 

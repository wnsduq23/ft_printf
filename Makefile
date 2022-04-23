# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/12 13:39:13 by junykim           #+#    #+#              #
#    Updated: 2022/04/23 20:09:45 by junykim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Variables
NAME	 	= libftprintf.a

CC			= gcc
CFLAG		= -Wall -Wextra -Werror
SRC_DIR		= src/
LIBFT 		= libft
INC 		= include
DEL 		= rm -f
ARC 		= ar -rc

#Sources
SRCS 		= ./src/ft_printf.c \
			  ./src/ft_printf_hex.c \
			  ./src/ft_printf_utils.c
OBJS 		= $(SRCS:.c=.o)

#Rules
all : $(NAME)

%.o : %.c
	$(CC) $(CFLAG) -c $< -o $@ -I$(INC)
	@echo "Compiling....... \t$<"

$(NAME) : $(OBJS)
	@make -C $(LIBFT)
	@cp libft/libft.a .
	@mv libft.a $(NAME)
	$(ARC) $@ $(OBJ)
	@echo "-----------------ft_printf compile finished-----------------"

clean :
	$(DEL) $(OBJS)
	@make clean -C $(LIBFT)
	@echo "ft_printf obj files has been deleted------------------------"

fclean : clean  
	$(DEL) $(NAME)
	$(DEL) $(LIBFT)/libft.a
	@echo "ft_printf archive files has been deleted" 

re : fclean all

.PHONY : all clean fclean re 

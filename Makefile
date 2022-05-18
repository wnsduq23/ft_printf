# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/12 13:39:13 by junykim           #+#    #+#              #
#    Updated: 2022/05/18 16:39:43 by junykim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Variables
NAME	 	= libftprintf.a

CC			= cc
CFLAG		= -Wall -Wextra -Werror
SRC_DIR		= src/
OBJ_DIR		= obj/
LIBFT 		= libft
INC 		= include
DEL 		= rm -f
ARC 		= ar rsc

#Sources
SRC_FILES	=	ft_printf_m \
				ft_printf_hex ft_printf_utils \
				ft_printf_format1 ft_printf_format2 \
				ft_printf_fp
SRC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
OBJF		=	create_dir

#Rules
all : $(NAME)

# Pipe : order-only prerequisite
$(OBJ_DIR)%.o : $(SRC_DIR)%.c | $(OBJF)
	$(CC) $(CFLAG) -c $< -o $@ -I $(INC)
	@echo "Compiling....... \t$<"

$(OBJF) :
	@mkdir -p $(OBJ_DIR)

$(NAME) : $(OBJ)
	@make -C $(LIBFT)
	@cp libft/libft.a .
	@mv libft.a $(NAME)
	$(ARC) $@ $(OBJ)
	@echo "-----------------ft_printf compile finished-----------------"

clean :
	$(DEL) -r $(OBJ_DIR)
	@make clean -C $(LIBFT)
	@echo "ft_printf obj files has been deleted------------------------"

fclean : clean  
	$(DEL) $(NAME)
	$(DEL) $(LIBFT)/libft.a
	@echo "ft_printf archive files has been deleted" 

re : 
	make fclean
	make all

.PHONY : all clean fclean re 

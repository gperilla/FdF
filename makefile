# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gperilla <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/06 16:43:17 by gperilla          #+#    #+#              #
#    Updated: 2018/01/05 10:01:31 by gperilla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc

WARNINGS = -Werror -Wextra -Wall

INC = -I. -I libft/

LIB = -L libft/ -lft -L minilibx_macos -lmlx -framework OpenGL -framework appKit

OBJC = main.c lecture.c to_the_matrix.c putpixel.c draw_line.c draw_iso.c\
	   draw_para.c my_math.c my_key_events.c

OBJ = $(OBJC:.c=.o)

COLOR = $(shell bash -c 'echo $$RANDOM')

define OK
	@$(eval COLOR=$(shell echo $$(($(COLOR)+1))))
	@tput setaf $(COLOR)
	@echo -n $1
	@tput setaf 10
	@echo ' [Compiled]'
	@tput sgr0
endef

define ISOK
	@$(eval COLOR=$(shell echo $$(($(COLOR)+1))))
	@tput setaf $(COLOR)
	@echo -n $1
	@tput setaf 10
	@echo ' [Run it you fool]'
	@tput sgr0
endef

all: $(NAME)

$(NAME): $(OBJ)
	@make -j3 -C libft
	@$(CC) $(INC) $(WARNINGS) $(LIB) $(OBJ) -o $@
	@$(call ISOK, $@)

test:
	@make -C libft
	@$(CC) $(INC) $(LIB) $(OBJC) -o $(NAME)

%.o: %.c
	@gcc -c $(INC) $(WARNINGS) $< -o $@
	$(call OK, $*)

clean:
	@make -C libft clean
	@rm -f $(OBJ)
	@echo 'removed .o'

fclean: clean
	@make -C libft fclean
	@rm -rf $(NAME) .depend
	@echo 'All your base are belong to us'

re: fclean all

.PHONY: all clean fclean re test

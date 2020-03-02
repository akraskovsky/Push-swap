# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/13 15:07:48 by fprovolo          #+#    #+#              #
#    Updated: 2020/03/02 16:58:46 by fprovolo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = push_swap
NAME2 = checker
FILES = parse_arguments\
		tools\
		commands\
		commands1\
		commands2\
		stack_push_pull\
		trim\
		sort_short\
		sort_main\
		push_to_a\

LFT_PATH = ./libft/
SRC_PATH = ./sources/
OBJ_PATH = ./objects/
INC_PATH = ./includes/

IFLAGS = -I $(LFT_PATH)/includes -I $(INC_PATH)
LFLAGS = -L $(LFT_PATH) -lft
CFLAGS = -Wall -Wextra -Werror

SRC = $(addprefix $(SRC_PATH), $(addsuffix .c, $(FILES)))
SRC1 = $(addprefix $(SRC_PATH), $(addsuffix .c, $(NAME1)))
SRC2 = $(addprefix $(SRC_PATH), $(addsuffix .c, $(NAME2)))

OBJ = $(addprefix $(OBJ_PATH), $(addsuffix .o, $(FILES)))
OBJ1 = $(addprefix $(OBJ_PATH), $(addsuffix .o, $(NAME1)))
OBJ2 = $(addprefix $(OBJ_PATH), $(addsuffix .o, $(NAME2)))

LIBFT = $(LFT_PATH)libft.a

all: $(NAME1) $(NAME2)

$(NAME1): $(LIBFT) $(OBJ_PATH) $(OBJ) $(OBJ1)
	gcc $(CFLAGS) $(IFLAGS) $(LFLAGS) $(OBJ) $(OBJ1) -o $(NAME1)

$(NAME2): $(LIBFT) $(OBJ_PATH) $(OBJ) $(OBJ2)
	gcc $(CFLAGS) $(IFLAGS) $(LFLAGS) $(OBJ) $(OBJ2) -o $(NAME2)

$(LIBFT):
	make -C $(LFT_PATH)

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(INC_PATH)push_swap.h
	gcc $(CFLAGS) $(IFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_PATH)
	make -C $(LFT_PATH) clean

fclean: clean
	rm -rf $(NAME1)
	make -C $(LFT_PATH) fclean

re: fclean all

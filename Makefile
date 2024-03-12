# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlara-na <jlara-na@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/23 19:24:55 by jlara-na          #+#    #+#              #
#    Updated: 2024/02/26 23:19:36 by jlara-na         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	push_swap

#-----------DIR PATHS------------

SRC_DIR			:=		src/
OBJ_DIR			:=		obj/
LIB_DIR			:=		lib/
INC_DIR			:=		inc/
LFT_DIR			:=		$(LIB_DIR)libft/

#-----------CMP PARAM------------

CC				:=		gcc
CFLAGS			:=		-g -O3 -Wall -Wextra -Werror #-fsanitize=address
HEADER			:=		-I$(INC_DIR) -I$(LFT_DIR)

#-----------ARCHIVE LIB----------

LIBFT			:=		$(LFT_DIR)libft.a

#-----------SHORT CUTS-----------

RM				:=		rm -f

#------------ANSI DEF------------

CLEAR			=		\033[2J\033[1;1H
DEF_COLOR		=		\033[0;39m
GRAY			=		\033[0;90m
RED				=		\033[0;91m
GREEN			=		\033[0;92m
YELLOW			=		\033[0;93m
YELLOWB			=		\033[0;93;5m
BLUE			=		\033[0;94m
MAGENTA			=		\033[0;95m
CYAN			=		\033[0;96m
WHITE			=		\033[0;97m

#---------SRC OBJ DEP INC---------

SRC_FILES		=		main				\
						msg					\
						automata			\
						actions				\
						ainit				\
						blist				\
						checker				\
						swap				\
						push				\
						rotate				\
						reverse_rotate		\
						sort_stack			\
						sort_less_than_five	\


SRC 			= 		$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 			= 		$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
DEPS 			= 		$(addprefix $(OBJ_DIR), $(addsuffix .d, $(SRC_FILES)))
INCS			= 		$(addprefix $(INCLUDE), $(addsuffix .h, $(INC_FILES)))

#----------CACHE----------

OBJF			=		.cache_exists

#---------------------------------

all:	makelibs
			@$(MAKE) $(NAME)

makelibs:
			@echo "\n			$(YELLOWB)⚙$(YELLOW)COMPILING LIBFT...$(CYAN)			\n"
			@$(MAKE) -C $(LFT_DIR)
			@echo "$(DEF_COLOR)"

-include	${DEPS}
$(NAME):	$(OBJ)
			@echo "\n$(BLUE)$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLXCC) -o $(NAME)$(DEF_COLOR)\n"
			@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
			@echo "$(CLEAR)$(GREEN)			✔PUSH_SWAP COMPILED CORRECTLY\n$(DEF_COLOR)"

bonus:
			@$(MAKE) all

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INCS) | $(OBJF)
			@echo "$(YELLOWB)			⚙$(YELLOW)COMPILING: $< ...$(DEF_COLOR)"
			@$(CC) $(CFLAGS) -MMD -c $< -o $@

$(OBJF):
			@mkdir -p $(OBJ_DIR)

$(LIBFT):
			@make -C $(LFT_DIR)
			@echo "$(GREEN)LIBFT	COMPILED$(DEF_COLOR)"
$(MLX):
			@make -C $(MLX_DIR)
			@echo "$(GREEN)MLX		COMPILED$(DEF_COLOR)"

clean:
			@echo "$(CLEAR)\n			🧹SWEEPING THE FLOOR🧹\n"
			@make clean -sC $(LFT_DIR)
			@echo "$(CYAN)LIBFT				$(GREEN)CLEANED$(DEF_COLOR)"
			@$(RM) -rf $(OBJ_DIR)
			@echo "$(CYAN)OBJ FILES			$(GREEN)CLEANED$(DEF_COLOR)"

fclean:		clean
			@$(RM) -f $(NAME)
			@echo "$(CYAN)PUSH_SWAP EXECUTABLE		$(GREEN)CLEANED$(DEF_COLOR)"
			@$(RM) -f $(LIBFT)
			@echo "$(CYAN)LIBFT .a			$(GREEN)CLEANED$(DEF_COLOR)"

re:			fclean
			@$(MAKE)
			@echo "$(GREEN)			✔PUSH_SWAP CLEANED, REBUILT & READY TO USE\n$(DEF_COLOR)"

norminette:
			@echo "$(CLEAR)"
			@echo "\n$(YELLOW)SRC FILES	$(YELLOW_B)NORMINETTED\n$(DEF_COLOR)"
			@norminette $(SRC) $(INCLUDE) | grep -v Norme -B1 || true
			@echo "\n$(YELLOW)INCLUDE FILES	$(YELLOW_B)NORMINETTED\n$(DEF_COLOR)"
			@norminette $(INC_DIR) | grep -v Norme -B1 || true

PHONY: all makelibs bonus clean fclean re norminette

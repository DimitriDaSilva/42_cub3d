# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/11 09:33:15 by dda-silv          #+#    #+#              #
#    Updated: 2021/02/23 19:34:21 by dda-silv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the program built
NAME			:=		cub3D

# Name directory
PATH_SRC		:=		src
PATH_BUILD		:=		build
PATH_LIBFT		:=		libft
PATH_LIBMLX		:=		libmlx

# List of sources
SRCS			:=		$(shell find $(PATH_SRC) -name *.c)
OBJS			:=		$(SRCS:%=$(PATH_BUILD)/%.o)
DEPS			:=		$(OBJS:.o=.d)
INC_DIRS		:=		$(shell find $(PATH_SRC) -type d)

# Compiler
CC				:=		gcc

# Flags - compilation
FLAG_WARNING	:=		-Wall -Wextra -Werror
FLAG_INC		:= 		$(addprefix -I, $(INC_DIRS))
FLAG_MAKEFILE	:=		-MMD -MP
FLAGS_COMP		:= 		$(FLAG_WARNING) $(FLAG_INC) $(FLAG_MAKEFILE)
FLAG_DEBUG		:= 		-g
FLAGS_COMP		:= 		$(FLAG_WARNING) $(FLAG_INC) $(FLAG_MAKEFILE) $(FLAG_DEBUG)

# Flags - memory leak check
FLAG_MEM_LEAK	:= 		-fsanitize=address

# Flags - linking
FLAG_LIBFT		:=		-Llibft -lft 
FLAG_LIBMLX		:=		-Llibmlx -lmlx
FLAG_MAC		:=		-framework OpenGL -framework AppKit
FLAGS_LINKINKG	:=		-lm $(FLAG_LIBFT) $(FLAG_LIBMLX) $(FLAG_MAC)

# Others commands
RM				:=		rm -rf
MLX				:=		libmlx.dylib

# Color Code and template code
_YELLOW			=		\e[38;5;184m
_GREEN			=		\e[38;5;46m
_RESET			=		\e[0m
_INFO			=		[$(_YELLOW)INFO$(_RESET)]
_SUCCESS		=		[$(_GREEN)SUCCESS$(_RESET)]

# Functions
all:					init $(NAME)
						@ echo "$(_SUCCESS) Compilation done"

debug:					FLAGS_COMP += $(FLAG_MEM_LEAK)
debug:					FLAGS_LINKINKG += $(FLAG_MEM_LEAK)
debug:					re

init:
						@ echo "$(_INFO) Initialize $(NAME)"
						@ make -C $(PATH_LIBFT)
						@ make -C $(PATH_LIBMLX)

$(NAME):				$(MLX) $(OBJS)
						$(CC) $(OBJS) -o $@ $(FLAGS_LINKINKG)


$(PATH_BUILD)/%.c.o:	%.c
						mkdir -p $(dir $@)
						$(CC) $(FLAGS_COMP) -c $< -o $@

bonus:					all

clean:
						@ $(RM) -rf $(PATH_BUILD)
						@ make -C $(PATH_LIBFT) clean
						@ make -C $(PATH_LIBMLX) clean
						@ echo "$(_INFO) Deleted files and directory"

fclean:					clean
						@ $(RM) $(NAME)
						@ make -C $(PATH_LIBFT) fclean

re:						fclean all

normH:
						norminette $(shell find $(PATH_SRC) -name *.h)
						@ make -C $(PATH_LIBFT) normH

normC:
						norminette $(SRCS)
						@ make -C $(PATH_LIBFT) normC

norm:					normH normC

old_normH:
						~/.old_norminette/norminette.rb $(shell find $(PATH_SRC) -name *.h)
						@ make -C $(PATH_LIBFT) old_normH

old_normC:
						~/.old_norminette/norminette.rb $(SRCS)
						@ make -C $(PATH_LIBFT) old_normC

old_norm:				old_normH old_normC

.PHONY:					all clean fclean re

-include $(DEPS)

# Source for some pieces of this Makefile: 
# https://makefiletutorial.com/#makefile-cookbook
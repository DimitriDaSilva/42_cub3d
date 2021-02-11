# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dda-silv <dda-silv@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/11 09:33:15 by dda-silv          #+#    #+#              #
#    Updated: 2021/02/11 12:18:46 by dda-silv         ###   ########.fr        #
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

# Flags - linking
FLAG_LIBFT		:=		-Llibft -lft 
FLAG_LIBMLX		:=		-Llibmlx -lmlx
FLAG_LIBX11		:=		-lX11 -lbsd -lXext
FLAGS_LINKINKG	:=		-lm $(FLAG_LIBFT) $(FLAG_LIBMLX) $(FLAG_LIBX11)

# Flags - debugging
FLAG_DEBUG		:= 		-g -fsanitize=address

# Others commands
RM				=		rm -rf

# Color Code and template code
_YELLOW			=		\e[38;5;184m
_GREEN			=		\e[38;5;46m
_RESET			=		\e[0m
_INFO			=		[$(_YELLOW)INFO$(_RESET)]
_SUCCESS		=		[$(_GREEN)SUCCESS$(_RESET)]

# Functions
all:					init $(NAME)
						@ echo "$(_SUCCESS) Compilation done"

debug:					FLAGS_COMP += $(FLAG_DEBUG)
debug:					FLAGS_LINKINKG += $(FLAG_DEBUG)
debug:					re

init:
						@ echo "$(_INFO) Initialize $(NAME)"
						@ make -C $(PATH_LIBFT)
						@ make -C $(PATH_LIBMLX)

$(NAME):				$(OBJS)
						$(CC) $(OBJS) -o $@ $(FLAGS_LINKINKG)


$(PATH_BUILD)/%.c.o:	%.c
						mkdir -p $(dir $@)
						$(CC) $(FLAGS_COMP) -c $< -o $@

clean:
						@ $(RM) -rf $(PATH_BUILD)
						@ make -C $(PATH_LIBFT) clean
						@ make -C $(PATH_LIBMLX) clean
						@ echo "$(_INFO) Deleted files and directory"

fclean:					clean
						@ $(RM) $(NAME)
						@ make -C $(PATH_LIBFT) fclean

re:						fclean all

.PHONY:					all clean fclean re

-include $(DEPS)

# Source for some pieces of this Makefile: 
# https://makefiletutorial.com/#makefile-cookbook
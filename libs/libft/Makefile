# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dds <dda-silv@student.42lisboa.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/11 09:33:15 by dda-silv          #+#    #+#              #
#    Updated: 2021/03/01 16:48:44 by dds              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the program built
NAME			:=		libft.a

# Name directory
PATH_SRC		:=		src
PATH_BUILD		:=		build

# List of sources
SRCS			:=		$(shell find $(PATH_SRC) -name *.c)
OBJS			:=		$(SRCS:%.c=$(PATH_BUILD)/%.o)
DEPS			:=		$(OBJS:.o=.d)
INC_DIRS		:=		$(shell find $(PATH_SRC) -type d)

# Compiler
CC				:=		gcc

# Flags - compilation
FLAG_WARNING	:=		-Wall -Wextra -Werror
FLAG_INC		:= 		$(addprefix -I, $(INC_DIRS))
FLAG_MAKEFILE	:=		-MMD -MP
FLAG_DEBUG		:= 		-g
FLAGS_COMP		:= 		$(FLAG_WARNING) $(FLAG_INC) $(FLAG_MAKEFILE) $(FLAG_DEBUG)

# Flags - memory leak check
FLAG_MEM_LEAK	:= 		-fsanitize=address

# Others commands
RM				:=		rm -rf
ARRC			:=		ar rcs

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
debug:					re

init:
						@ echo "$(_INFO) Initialize $(NAME)"

$(NAME):				$(OBJS)
						$(ARRC) $@ $(OBJS)


$(PATH_BUILD)/%.o:		%.c
						mkdir -p $(dir $@)
						$(CC) $(FLAGS_COMP) -c $< -o $@

clean:
						@ $(RM) -rf $(PATH_BUILD)
						@ echo "$(_INFO) Deleted files and directory"

fclean:					clean
						@ $(RM) $(NAME)

re:						fclean all

old_normH:
						~/.old_norminette/norminette.rb $(shell find $(PATH_SRC) -name *.h)

old_normC:
						~/.old_norminette/norminette.rb $(SRCS)

old_norm:				old_normH old_normC

normH:
						norminette $(shell find $(PATH_SRC) -name *.h)

normC:
						norminette $(SRCS)

norm:					normH normC

.PHONY:					all clean fclean re

-include $(DEPS)

# Source for some pieces of this Makefile: 
# https://makefiletutorial.com/#makefile-cookbook
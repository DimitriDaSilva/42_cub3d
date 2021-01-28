# Name of the program built
NAME			=		cub3d

# Name directory
PATH_SRC		=		cub3d_code/srcs
PATH_OBJ		=		cub3d_code/objs
PATH_INC		=		cub3d_code/includes
PATH_LIBFT		=		libft
PATH_LIBMLX		=		libmlx

# List of sources
SRCS			=		$(wildcard $(PATH_SRC)/*.c)
OBJS			=		$(addprefix $(PATH_OBJ)/, $(notdir $(SRCS:.c=.o)))
INCS			=		$(addprefix $(PATH_INC)/, *.h)

# Commands of compilation
COMP			=		gcc
COMP_FLAG		= 		-Wall -Wextra -Werror 
COMP_ADD		=		-I$(PATH_INC)

# Others commands
RM				=		rm -f

# Color Code and template code
_YELLOW			=		\e[38;5;184m
_GREEN			=		\e[38;5;46m
_RESET			=		\e[0m
_INFO			=		[$(_YELLOW)INFO$(_RESET)]
_SUCCESS		=		[$(_GREEN)SUCCESS$(_RESET)]

# Functions
all:					init $(NAME)
						@ echo "$(_SUCCESS) Compilation done"

init:
						@ echo "$(_INFO) Initialize $(NAME)"
						@ $(shell mkdir -p $(PATH_OBJ))
						@ make -C $(PATH_LIBFT)
						@ make -C $(PATH_LIBMLX)

$(NAME): 				$(OBJS) $(INCS)
						@ $(COMP) $(COMP_FLAG) $(COMP_ADD) -o $(NAME) $(OBJS) -Llibft -lft -Llibmlx -lmlx -lX11 -lbsd -lm -lXext

$(PATH_OBJ)/%.o: 		$(PATH_SRC)/%.c $(INCS)
						@ $(COMP) $(COMP_FLAG) $(COMP_ADD) -c $< -o $@
						@ echo "$(_INFO) Compilation of $*"

clean:
						@ $(RM) -rf $(PATH_OBJ)
						@ make -C $(PATH_LIBFT) clean
						@ make -C $(PATH_LIBMLX) clean
						@ echo "$(_INFO) Deleted files and directory"

fclean:					clean
						@ $(RM) -rf $(NAME)
						@ make -C $(PATH_LIBFT) fclean

re:						fclean all

normH:					all
						~/.norminette/norminette.rb ./$(PATH_INC)/*.h

normC:					all
						~/.norminette/norminette.rb $(SRCS) $(PATH_SRC)/cub3d.c

norm:					normH normC

.PHONY:					all clean fclean re
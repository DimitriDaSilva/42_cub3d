# # Name of the program built
# NAME			:=		cub3D

# # Name directory
# PATH_SRC		:=		cub3D_code/src
# PATH_OBJ		:=		cub3D_code/build
# PATH_INC		:=		cub3D_code/includes
# PATH_LIBFT		:=		libft
# PATH_LIBMLX		:=		libmlx

# # List of sources
# SRCS			:=		$(shell find $(PATH_SRC) -name "*.c")
# OBJS			:=		$(addprefix $(PATH_OBJ)/, $(notdir $(SRCS:.c=.o)))
# # OBJS			:=		$(SRCS:%=$(PATH_OBJ)/%.o)
# INCS			:=		$(shell find $(PATH_SRC) -name "*.h")

# # Compiler
# COMP			:=		gcc

# # Flags
# FLAG_WARNING	:=		-Wall -Wextra -Werror
# FLAG_LEAK_CHECK	:= 		-ggdb -fsanitize=address -fno-omit-frame-pointer
# FLAG_LLDB		:=		-g
# FLAG_INC		:= 		$(addprefix -I, $(PATH_INC))
# FLAGS			:= 		$(FLAG_WARNING) $(FLAG_LEAK_CHECK) $(FLAG_LLDB) $(FLAG_INC)

# # Others commands
# RM				:=		rm -f

# # Color Code and template code
# _YELLOW			:=		\e[38;5;184m
# _GREEN			:=		\e[38;5;46m
# _RESET			:=		\e[0m
# _INFO			:=		[$(_YELLOW)INFO$(_RESET)]
# _SUCCESS		:=		[$(_GREEN)SUCCESS$(_RESET)]

# # Functions
# all:					init $(NAME)
# 						@ echo "$(_SUCCESS) Compilation done"

# init:
# 						@ echo "$(_INFO) Initialize $(NAME)"
# 						@ make -C $(PATH_LIBFT)
# 						@ make -C $(PATH_LIBMLX)

# $(NAME): 				$(OBJS) $(INCS)
# 						@ $(COMP) $(FLAGS) -o $(NAME) $(OBJS) -Llibft -lft -Llibmlx -lmlx -lX11 -lbsd -lm -lXext

# $(PATH_OBJ)/%.o:		$(SRCS)
# 						@ $(shell mkdir -p $(PATH_OBJ))
# 						@ $(COMP) $(FLAGS) -c $< -o $@
# 						@ echo "$(_INFO) Compilation of $*"

# # $(PATH_OBJ)/%.o:		$(SRCS)
# # $(PATH_OBJ)/%.o: 		$(PATH_SRC)/%.c $(INCS)
# # 						@ $(COMP) $(FLAGS) -c $< -o $@
# # 						@ echo "$(_INFO) Compilation of $*"

# clean:
# 						@ $(RM) -rf $(PATH_OBJ)
# 						@ make -C $(PATH_LIBFT) clean
# 						@ make -C $(PATH_LIBMLX) clean
# 						@ echo "$(_INFO) Deleted files and directory"

# fclean:					clean
# 						@ $(RM) -rf $(NAME)
# 						@ make -C $(PATH_LIBFT) fclean

# re:						fclean all

# normH:
# 						~/.norminette/norminette.rb $(INCS)
# 						@ make -C $(PATH_LIBFT) normH

# normC:
# 						~/.norminette/norminette.rb $(SRCS)
# 						@ make -C $(PATH_LIBFT) normC

# norm:					normH normC

# .PHONY:					all clean fclean re



# Name of the program built
NAME			=		cub3D

# Name directory
PATH_SRC		=		cub3D_code/src
PATH_OBJ		=		cub3D_code/objs
PATH_INC		=		cub3D_code/includes
PATH_LIBFT		=		libft
PATH_LIBMLX		=		libmlx

# List of sources
SRCS			:=		$(shell find $(PATH_SRC) -name "*.c")
# SRCS			=		$(wildcard $(PATH_SRC)/*.c)
OBJS			=		$(addprefix $(PATH_OBJ)/, $(notdir $(SRCS:.c=.o)))
INCS			=		$(addprefix $(PATH_INC)/, *.h)

# Commands of compilation
COMP			=		gcc
COMP_FLAG		= 		-Wall -Wextra -Werror -ggdb -fsanitize=address -fno-omit-frame-pointer -g
# COMP_FLAG		= 		-Wall -Wextra -Werror
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

$(PATH_OBJ)/%.o: 		$(SRCS) $(INCS)
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

normH:
						~/.norminette/norminette.rb $(INCS)
						@ make -C $(PATH_LIBFT) normH

normC:
						~/.norminette/norminette.rb $(SRCS)
						@ make -C $(PATH_LIBFT) normC

norm:					normH normC

.PHONY:					all clean fclean re
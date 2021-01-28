# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/11 15:58:25 by dda-silv          #+#    #+#              #
#    Updated: 2021/01/12 10:37:58 by dda-silv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	$(wildcard ./srcs/*/*.c)

OBJS	=	$(SRCS:.c=.o)

INCDIR  =	includes

NAME	=	libft.a

CC		=	gcc

ARRC	=	ar rcs

RM		=	rm -f

CFLAGS	=	-Wall -Wextra -Werror 

.c.o:
			$(CC) -g $(CFLAGS) -c $^ -o $(<:.c=.o) -I$(INCDIR)

$(NAME):	$(OBJS)
			$(ARRC) $(NAME) $(OBJS)

all:		$(NAME)

clean:
			$(RM) $(OBJS) $(BONUS_OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: falmeida <falmeida@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/24 13:48:51 by falmeida          #+#    #+#              #
#    Updated: 2021/07/27 20:05:56 by falmeida         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = server

SRC = server.c	\
		utils.c	\

NAME2 = client

SRC2 = client.c	\
		utils.c	\

CFLAGS = -Wall -Wextra -Werror -g

OBJS = $(SRC:.c=.o)

OBJS2 = $(SRC2:.c=.o)

$(NAME) : $(OBJS)
	gcc $(OBJS) $(FLAGS) -o $(NAME)

$(NAME2) : $(OBJS2)
	gcc $(OBJS2) $(FLAGS) -o $(NAME2)

all: $(NAME) $(NAME2)

clean:
	/bin/rm -rf $(OBJS)
	/bin/rm -rf $(OBJS2)

fclean:
	/bin/rm -f $(NAME)
	/bin/rm -f $(NAME2)

re: fclean all
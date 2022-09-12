# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nnemeth <nnemeth@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/26 16:23:59 by nemethnikol       #+#    #+#              #
#    Updated: 2022/09/09 15:23:27 by nnemeth          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = 	gcc

CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

OBJS = $(SRC:.c=.o)

RM  = rm -fr

SRC = *.c

all: $(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(SRC)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all
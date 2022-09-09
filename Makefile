# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rel-maza <rel-maza@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/30 12:15:36 by rel-maza          #+#    #+#              #
#    Updated: 2022/08/30 17:13:17 by rel-maza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = gcc

FLAGS = -Wall -Wextra -Werror -pthread

SRC = philo.c utils.c check_error.c create_philo.c insert.c check_is_died.c

OBJ = $(SRC:.c=.o)

HEADER = philo.h

all : $(NAME)

%.o : %.c
	$(CC) $(FLAGS) -c $<

$(NAME): $(OBJ) $(HEADER)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean :
	rm $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all
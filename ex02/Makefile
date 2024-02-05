# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbrunet <gbrunet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/01 14:02:07 by gbrunet           #+#    #+#              #
#    Updated: 2024/02/01 14:09:07 by gbrunet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = global_bank_united

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = Account.cpp tests.cpp

OBJ = Account.o tests.o

all : $(NAME)

%.o : %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean :
	$(RM) $(OBJ)

fclean :
	make clean
	$(RM) $(NAME)

re :
	make fclean
	make all

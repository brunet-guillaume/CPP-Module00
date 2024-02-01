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

NAME = my_awesome_phonebook

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = Contact.cpp PhoneBook.cpp main.cpp

OBJ = Contact.o PhoneBook.o main.o

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

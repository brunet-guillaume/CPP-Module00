/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <gbrunet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 09:40:07 by gbrunet           #+#    #+#             */
/*   Updated: 2024/02/15 09:39:23 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>
#include "PhoneBook.hpp"
#include "Contact.hpp"

int	main(void) {
	PhoneBook	phone_book;
	char		line[512];

	std::cout << "> ";
	while (std::cin.getline(line, 512) && strcmp(line, "EXIT") != 0)
	{
		if (strcmp(line, "ADD") == 0)
			phone_book.add();
		else if (strcmp(line, "SEARCH") == 0)
			phone_book.search();
		std::cout << "> ";
	}
	std::cout << std::endl;
	return (0);
}

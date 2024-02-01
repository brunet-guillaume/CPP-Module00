/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <gbrunet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 09:37:26 by gbrunet           #+#    #+#             */
/*   Updated: 2024/02/01 14:02:03 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include <sstream>
#include "PhoneBook.hpp"
#include "Contact.hpp"

std::string	reduce(std::string str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

int	is_valid_number(std::string str)
{
	int	start;

	start = 0;
	if (str[0] == '-' || str[0] == '+')
		start = 1;
	for (unsigned long i = start; i < str.length(); i++) {
		if (!isdigit(str[i]))
			return (0);
	}
	return (1);
}

PhoneBook::PhoneBook(void) {
	return ;
}

PhoneBook::~PhoneBook(void) {
	return ;
}

void	PhoneBook::add(void) {
	Contact	contact;

	if (contacts.size() >= 8)
		contacts.pop_front();
	contacts.push_back(contact);
}

void	PhoneBook::print_phonebook(void)
{
	unsigned long	i;

	std::cout << "+----------+----------+----------+----------+" << std::endl;
	std::cout << "|     index|first name| last name|  nickname|" << std::endl;
	std::cout << "+----------+----------+----------+----------+" << std::endl;
	i = 0;
	for (std::list<Contact>::iterator it = this->contacts.begin();
			it != this->contacts.end(); ++it) {
		std::cout << "|";
		std::cout.width(10);
		std::cout << i << "|";
		std::cout.width(10);
		std::cout << reduce(it->get_first_name()) << "|";
		std::cout.width(10);
		std::cout << reduce(it->get_last_name()) << "|";
		std::cout.width(10);
		std::cout << reduce(it->get_nickname()) << "|" << std::endl;
		i++;
	}
	std::cout << "+----------+----------+----------+----------+" << std::endl;
}

void	PhoneBook::search(void) {
	unsigned long	i;
	std::string		index("");

	this->print_phonebook();
	if (this->contacts.size() == 0)
		return ;
	while (index.empty())
	{
		std::cout << "index : ";
		std::getline(std::cin, index);
		if (is_valid_number(index))
		{
			std::istringstream(index) >> i;
			if (i > this->contacts.size() - 1 || i < 0)
				index = "";
		}
		else
			index = "";
	}
	std::list<Contact>::iterator it = contacts.begin();
	advance(it, i);
	it->print();
}

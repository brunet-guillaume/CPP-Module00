/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <gbrunet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 09:37:26 by gbrunet           #+#    #+#             */
/*   Updated: 2024/02/16 12:08:46 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
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
	this->nb_contacts = 0;
	return ;
}

PhoneBook::~PhoneBook(void) {
	return ;
}

void	PhoneBook::add(void) {
	this->contacts[this->nb_contacts % 8].set_first_name();
	this->contacts[this->nb_contacts % 8].set_last_name();
	this->contacts[this->nb_contacts % 8].set_nickname();
	this->contacts[this->nb_contacts % 8].set_phone_number();
	this->contacts[this->nb_contacts % 8].set_darkest_secret();
	this->nb_contacts++;
}

void	PhoneBook::print_phonebook(void)
{
	unsigned long	nb_entries;

	std::cout << "┌──────────┬──────────┬──────────┬──────────┐" << std::endl;
	std::cout << "│\e[1;32m     index\e[0m│\e[1;32mfirst name\e[0m│\e[1;32m last name\e[0m│\e[1;32m  nickname\e[0m│" << std::endl;
	std::cout << "├──────────┼──────────┼──────────┼──────────┤" << std::endl;
	if (this->nb_contacts > 7)
		nb_entries = 8;
	else
		nb_entries = this->nb_contacts;
	for (unsigned int i = 0; i < nb_entries; i++) {
		std::cout << "│";
		if (i % 2)
			std::cout << "\e[0;33m";
		else
			std::cout << "\e[0;35m";
		std::cout.width(10);
		std::cout << i << "\e[0m│";
		if (i % 2)
			std::cout << "\e[0;33m";
		else
			std::cout << "\e[0;35m";
		std::cout.width(10);
		std::cout << reduce(this->contacts[i].get_first_name()) << "\e[0m│";
		if (i % 2)
			std::cout << "\e[0;33m";
		else
			std::cout << "\e[0;35m";
		std::cout.width(10);
		std::cout << reduce(this->contacts[i].get_last_name()) << "\e[0m│";
		if (i % 2)
			std::cout << "\e[0;33m";
		else
			std::cout << "\e[0;35m";
		std::cout.width(10);
		std::cout << reduce(this->contacts[i].get_nickname()) << "\e[0m│" << std::endl;
	}
	std::cout << "└──────────┴──────────┴──────────┴──────────┘" << std::endl;
}

void	PhoneBook::search(void) {
	unsigned long	i;
	std::string		index("");
	unsigned int	nb_try;
	unsigned long	nb_entries;

	if (this->nb_contacts > 7)
		nb_entries = 8;
	else
		nb_entries = this->nb_contacts;
	this->print_phonebook();
	if (this->nb_contacts == 0)
		return ;
	std::cout << "\e[1mindex > \e[0m";
	nb_try = 0;
	i = 8;
	while (std::getline(std::cin, index)) {
		i = 8;
		if (index.empty()) {
			std::cout << "\e[1mindex > \e[0m";
			continue ;
		}
		if (is_valid_number(index)) {
			nb_try++;
			std::istringstream(index) >> i;
			if (i >= nb_entries || i < 0) {
				if (nb_try < 5) {
					std::cerr << "\e[0;31mInvalid index: try again\e[0m" << std::endl;
					std::cout << "\e[1mindex > \e[0m";
					continue ;
				}
				std::cerr << "\e[0;31mInvalid index: SEARCH exited\e[0m" << std::endl;
				return ;
			}
			else
				break ;
		}
		else {
			nb_try++;
			if (nb_try < 5) {
				std::cerr << "\e[0;31mInvalid index: try again\e[0m" << std::endl;
				std::cout << "\e[1mindex > \e[0m";
				continue ;
			}
			std::cerr << "\e[0;31mInvalid index: SEARCH exited\e[0m" << std::endl;
			return ;
		}
	}
	if (i < nb_entries)
		this->contacts[i].print();
	else
		std::cout << std::endl;
}

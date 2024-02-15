/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <gbrunet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 09:37:26 by gbrunet           #+#    #+#             */
/*   Updated: 2024/02/15 10:06:59 by gbrunet          ###   ########.fr       */
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

	std::cout << "+----------+----------+----------+----------+" << std::endl;
	std::cout << "|     index|first name| last name|  nickname|" << std::endl;
	std::cout << "+----------+----------+----------+----------+" << std::endl;
	if (this->nb_contacts > 7)
		nb_entries = 8;
	else
		nb_entries = this->nb_contacts;
	for (unsigned int i = 0; i < nb_entries; i++) {
		std::cout << "|";
		std::cout.width(10);
		std::cout << i << "|";
		std::cout.width(10);
		std::cout << reduce(this->contacts[i].get_first_name()) << "|";
		std::cout.width(10);
		std::cout << reduce(this->contacts[i].get_last_name()) << "|";
		std::cout.width(10);
		std::cout << reduce(this->contacts[i].get_nickname()) << "|" << std::endl;
	}
	std::cout << "+----------+----------+----------+----------+" << std::endl;
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
	std::cout << "index > ";
	nb_try = 0;
	i = 8;
	while (std::getline(std::cin, index)) {
		i = 8;
		if (index.empty()) {
			std::cout << "index > ";
			continue ;
		}
		if (is_valid_number(index)) {
			nb_try++;
			std::istringstream(index) >> i;
			if (i >= nb_entries || i < 0) {
				if (nb_try < 5) {
					std::cerr << "Invalid index: try again" << std::endl;
					std::cout << "index > ";
					continue ;
				}
				std::cerr << "Invalid index: SEARCH exited" << std::endl;
				return ;
			}
			else
				break ;
		}
		else {
			nb_try++;
			if (nb_try < 5) {
				std::cerr << "Invalid index: try again" << std::endl;
				std::cout << "index > ";
				continue ;
			}
			std::cerr << "Invalid index: SEARCH exited" << std::endl;
			return ;
		}
	}
	if (i < nb_entries)
		this->contacts[i].print();
	else
		std::cout << std::endl;
}

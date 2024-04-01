/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <gbrunet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 09:56:16 by gbrunet           #+#    #+#             */
/*   Updated: 2024/02/16 12:05:21 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>

Contact::Contact(void) {
	return ;
}

Contact::~Contact(void) {
	return ;
}

int	Contact::checkPrintable(std::string str) {
	for (unsigned int i = 0; i < str.length(); i++) {
		if (!std::isprint(str[i]))
			return (0);
	}
	return (1);
}

void	Contact::print(void){
	std::cout << "\e[1mFirst name : \e[0;32m" << this->first_name << "\e[0m" << std::endl;
	std::cout << "\e[1mLast name : \e[0;32m" << this->last_name << "\e[0m" << std::endl;
	std::cout << "\e[1mNickname : \e[0;32m" << this->nickname << "\e[0m" << std::endl;
	std::cout << "\e[1mPhone number \e[0;32m: " << this->phone_number << "\e[0m" << std::endl;
	std::cout << "\e[1mDarkest secret : \e[0;32m" << this->darkest_secret << "\e[0m" << std::endl;
}

void	Contact::set_first_name(void) {
	std::cout << "\e[1mFirst name > \e[0m";
	while (std::getline(std::cin, this->first_name)) {
		if (!this->first_name.empty() && this->checkPrintable(this->first_name))
			break ;
		std::cerr << "\e[0;31mThis field can't be empty, and must contains only printable char\e[0m" << std::endl;
		std::cout << "\e[1mFirst name > \e[0m";
	}
	if (this->first_name.empty())
		std::cout << std::endl;
}

void	Contact::set_last_name(void) {
	std::cout << "\e[1mLast name > \e[0m";
	while (std::getline(std::cin, this->last_name)) {
		if (!this->last_name.empty() && this->checkPrintable(this->last_name))
			break ;
		std::cerr << "\e[0;31mThis field can't be empty, and must contains only printable char\e[0m" << std::endl;
		std::cout << "\e[1mLast name > \e[0m";
	}
	if (this->last_name.empty())
		std::cout << std::endl;
}

void	Contact::set_nickname(void) {
	std::cout << "\e[1mNickname > \e[0m";
	while (std::getline(std::cin, this->nickname)) {
		if (!this->nickname.empty() && this->checkPrintable(this->nickname))
			break ;
		std::cerr << "\e[0;31mThis field can't be empty, and must contains only printable char\e[0m" << std::endl;
		std::cout << "\e[1mNickname > \e[0m";
	}
	if (this->nickname.empty())
		std::cout << std::endl;
}

void	Contact::set_phone_number(void) {
	std::cout << "\e[1mPhone number > \e[0m";
	while (std::getline(std::cin, this->phone_number)) {
		if (!this->phone_number.empty() && this->checkPrintable(this->phone_number))
			break ;
		std::cerr << "\e[0;31mThis field can't be empty, and must contains only printable char\e[0m" << std::endl;
		std::cout << "\e[1mPhone number > \e[0m";
	}
	if (this->phone_number.empty())
		std::cout << std::endl;
}

void	Contact::set_darkest_secret(void) {
	std::cout << "\e[1mDarkest secret > \e[0m";
	while (std::getline(std::cin, this->darkest_secret)) {
		if (!this->darkest_secret.empty() && this->checkPrintable(this->darkest_secret))
			break ;
		std::cerr << "\e[0;31mThis field can't be empty, and must contains only printable char\e[0m" << std::endl;
		std::cout << "\e[1mDarkest secret > \e[0m";
	}
	if (this->darkest_secret.empty())
		std::cout << std::endl;
}

std::string	Contact::get_first_name(void) {
	return (this->first_name);
}

std::string	Contact::get_last_name(void) {
	return (this->last_name);
}

std::string	Contact::get_nickname(void) {
	return (this->nickname);
}

std::string	Contact::get_phone_number(void) {
	return (this->phone_number);
}

std::string	Contact::get_darkest_secret(void) {
	return (this->darkest_secret);
}

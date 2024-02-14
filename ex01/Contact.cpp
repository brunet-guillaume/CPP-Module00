/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <gbrunet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 09:56:16 by gbrunet           #+#    #+#             */
/*   Updated: 2024/02/14 10:20:14 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>

Contact::Contact(void) {
	this->set_first_name();
	this->set_last_name();
	this->set_nickname();
	this->set_phone_number();
	this->set_darkest_secret();
	return ;
}

Contact::~Contact(void) {
	return ;
}

void	Contact::print(void){
	std::cout << "First name : " << this->first_name << std::endl;
	std::cout << "Last name : " << this->last_name << std::endl;
	std::cout << "Nickname : " << this->nickname << std::endl;
	std::cout << "Phone number : " << this->phone_number << std::endl;
	std::cout << "Darkest secret : " << this->darkest_secret << std::endl;
}

void	Contact::set_first_name(void) {
	std::cout << "First name > ";
	std::getline(std::cin, this->first_name);
	if (this->first_name.empty())
		this->set_first_name();
}

void	Contact::set_last_name(void) {
	std::cout << "Last name > ";
	std::getline(std::cin, this->last_name);
	if (this->last_name.empty())
		this->set_last_name();
}

void	Contact::set_nickname(void) {
	std::cout << "Nickname > ";
	std::getline(std::cin, this->nickname);
	if (this->nickname.empty())
		this->set_nickname();
}

void	Contact::set_phone_number(void) {
	std::cout << "Phone number > ";
	std::getline(std::cin, this->phone_number);
	if (this->phone_number.empty())
		this->set_phone_number();
}

void	Contact::set_darkest_secret(void) {
	std::cout << "Darkest secret > ";
	std::getline(std::cin, this->darkest_secret);
	if (this->darkest_secret.empty())
		this->set_darkest_secret();
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

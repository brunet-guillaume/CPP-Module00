/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <gbrunet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 09:35:41 by gbrunet           #+#    #+#             */
/*   Updated: 2024/02/01 13:54:42 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include <list>
# include "Contact.hpp"

class PhoneBook {
	private:
		std::list<Contact> contacts;
		
		void	print_phonebook(void);

	public:
		PhoneBook(void);
		~PhoneBook(void);

		void	add(void);
		void	search(void);
};

#endif

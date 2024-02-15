/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <gbrunet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 09:35:41 by gbrunet           #+#    #+#             */
/*   Updated: 2024/02/15 09:19:16 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.hpp"

class PhoneBook {
	private:
		Contact 			contacts[8];
		unsigned int		nb_contacts;

		void	print_phonebook(void);
	public:
		PhoneBook(void);
		~PhoneBook(void);

		void	add(void);
		void	search(void);
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <gbrunet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 09:46:06 by gbrunet           #+#    #+#             */
/*   Updated: 2024/02/16 11:58:22 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

# include <iostream>

class Contact {
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;

	public:
		Contact(void);
		~Contact(void);

		int			checkPrintable(std::string str);
		void		print(void);
		void		set_first_name(void);
		void		set_last_name(void);
		void		set_nickname(void);
		void		set_phone_number(void);
		void		set_darkest_secret(void);
		std::string	get_first_name(void);
		std::string	get_last_name(void);
		std::string	get_nickname(void);
		std::string	get_phone_number(void);
		std::string	get_darkest_secret(void);
};

#endif

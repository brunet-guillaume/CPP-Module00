/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <gbrunet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 08:45:13 by gbrunet           #+#    #+#             */
/*   Updated: 2024/02/14 10:07:50 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>

int	main(int ac, char **av)
{
	int	j;
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else {
		for (int i = 1; i < ac; i++) {
			j = -1;
			while (av[i][++j])
				std::cout << (char)std::toupper(av[i][j]);
		}
		std::cout << std::endl;
	}
	return (0);
}

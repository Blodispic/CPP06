/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rozhou <rozhou@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 11:07:09 by rozhou            #+#    #+#             */
/*   Updated: 2022/04/12 11:07:09 by rozhou           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "conv.hpp"

int main(int argc, char **argv)
{
	char * endPtr;

    if (argc != 2)
    {
        std::cout << "Wrong Arguments" << std::endl;
		return (0);
	}

	double	d = std::strtod(argv[1], &endPtr);
	if (endPtr == argv[1] && std::char_traits<char>::length(argv[1]) == 1)
		d = static_cast<int>(argv[1][0]);
	else if (((endPtr[0] && endPtr[0] != 'f') || std::char_traits<char>::length(endPtr) > 1))
		d = static_cast<double>(NAN);

	char c = static_cast<char>(d);
	int		i = static_cast<int>(d);
	float	f = static_cast<float>(d);

	if (d < 0 || d > 127 || std::isnan(d))
		std::cout << "Char: " << "impossible" << std::endl;
	else if (c <= 31 && c >= 0)
		std::cout << "Char: " << "Non displayable" << std::endl;
	else
		std::cout << "Char: '" << c << "'" << std::endl;


	if (d < -2147483648 || d > 2147483647 || std::isnan(d))
		std::cout << "Int: " << "impossible" << std::endl;
	else
		std::cout << "Int: " << i << std::endl;

	std::cout << std::fixed << std::setprecision(1) << "Float: " << f << "f" << std::endl;

	std::cout << "Double: " << d << std::endl;
	return (0);
}
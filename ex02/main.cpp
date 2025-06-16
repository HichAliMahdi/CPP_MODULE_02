/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hali-mah <hali-mah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 11:21:05 by hali-mah          #+#    #+#             */
/*   Updated: 2025/06/16 17:57:38 by hali-mah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main()
{
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));

    // Mendatory part
    std::cout << "Mendatory tests :\n";
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max(a, b) << std::endl;

    std::cout << "\nAditionnal tests :\n";

    Fixed c(10);
    Fixed d(3.5f);

    // My additions
    std::cout << std::boolalpha;
    std::cout << "c > d : " << (c > d) << std::endl;
    std::cout << "c < d : " << (c < d) << std::endl;
    std::cout << "c >= d : " << (c >= d) << std::endl;
    std::cout << "c <= d : " << (c <= d) << std::endl;
    std::cout << "c == d : " << (c == d) << std::endl;
    std::cout << "c != d : " << (c != d) << std::endl;

    // Arethmetic operators 
    std::cout << "c + d = " << (c + d) << std::endl;
    std::cout << "c - d = " << (c - d) << std::endl;
    std::cout << "c * d = " << (c * d) << std::endl;
    std::cout << "c / d = " << (c / d) << std::endl;

    // Incrementation / decrementation
    Fixed e(1);
    std::cout << "e initial = " << e << std::endl;
    std::cout << "++e = " << ++e << std::endl;
    std::cout << "e++ = " << e++ << std::endl;
    std::cout << "e = " << e << std::endl;
    std::cout << "--e = " << --e << std::endl;
    std::cout << "e-- = " << e-- << std::endl;
    std::cout << "e = " << e << std::endl;

    // Fonctions min/max
    std::cout << "min(c, d) = " << Fixed::min(c, d) << std::endl;
    std::cout << "max(c, d) = " << Fixed::max(c, d) << std::endl;

    const Fixed f(7);
    const Fixed g(15);

    std::cout << "min(f, g) = " << Fixed::min(f, g) << std::endl;
    std::cout << "max(f, g) = " << Fixed::max(f, g) << std::endl;

    return 0;
}

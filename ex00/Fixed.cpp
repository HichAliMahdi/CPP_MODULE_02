/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hali-mah <hali-mah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:26:25 by hali-mah          #+#    #+#             */
/*   Updated: 2025/06/15 21:43:46 by hali-mah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Default constructor
Fixed::Fixed() : _value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

// Copy constructor
Fixed::Fixed(const Fixed& src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

// Copy assignement operator
Fixed& Fixed::operator=(const Fixed& rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
        this->_value = rhs.getRawBits();
    return *this;
}

// Destructor
Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

//Return the raw value
int     Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->_value;
}

// Sets the raw value
void    Fixed::setRawBits(int const raw)
{
    this->_value = raw;    
}

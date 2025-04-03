/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hali-mah <hali-mah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 10:49:38 by hali-mah          #+#    #+#             */
/*   Updated: 2025/04/03 11:16:58 by hali-mah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Default constructor
Fixed::Fixed() : _value(0)
{
    std::cout << "Default constructor called" << std::endl;
}


// Int constructor
Fixed::Fixed(const int n)
{
    std::cout << "Int constructor called" << std::endl;
    _value = n << _fractionalBits;
}

// Float constructor
Fixed::Fixed(const float n)
{
    std::cout << "Float constructor called" << std::endl;
    _value = roundf(n * (1 << _fractionalBits));
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
    std::cout << "Copy assignement operator called" << std::endl;
    if (this != &rhs)
        this->_value = rhs.getRawBits();
    return *this;
}

// Destructor
Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

// Return the raw value
int     Fixed::getRawBits( void ) const
{
    return this->_value;
}

// Sets the raw value
void    Fixed::setRawBits(int const raw)
{
    this->_value = raw;    
}

//toFloat function
float   Fixed::toFloat( void ) const
{
    return static_cast<float>(_value) / (1 << _fractionalBits);
}

//toInt function
int     Fixed::toInt( void ) const
{
    return _value >> _fractionalBits;
}

// operator declataions
std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return os;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hali-mah <hali-mah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 11:20:52 by hali-mah          #+#    #+#             */
/*   Updated: 2025/04/03 12:12:25 by hali-mah         ###   ########.fr       */
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

//Bool operators
// Greater than operator
bool Fixed::operator>(const Fixed& rhs) const
{
    return this->_value > rhs._value;
}

// Less than operator
bool Fixed::operator<(const Fixed& rhs) const
{
    return this->_value < rhs._value;
}

// Greater than or equal operator
bool Fixed::operator>=(const Fixed& rhs) const
{
    return this->_value >= rhs._value;
}

// Less than or equal operator
bool Fixed::operator<=(const Fixed& rhs) const
{
    return this->_value <= rhs._value;
}

// Equality operator
bool Fixed::operator==(const Fixed& rhs) const
{
    return this->_value == rhs._value;
}

// Inequality operator
bool Fixed::operator!=(const Fixed& rhs) const
{
    return this->_value != rhs._value;
}

// Arithmetic operations
Fixed Fixed::operator+(const Fixed& rhs) const
{
    Fixed result;
    result.setRawBits(this->_value + rhs._value);
    return result;
}

Fixed Fixed::operator-(const Fixed& rhs) const
{
    Fixed result;
    result.setRawBits(this->_value - rhs._value);
    return result;
}

Fixed Fixed::operator*(const Fixed& rhs) const
{
    Fixed result;
    result.setRawBits((this->_value * rhs._value) >> _fractionalBits);
    return result;
}

Fixed Fixed::operator/(const Fixed& rhs) const
{
    if (rhs._value == 0)
    {
        std::cerr << "Division by 0 not possible in R" << std::endl;
        return Fixed();
    }
    Fixed result;
    result.setRawBits((this->_value << _fractionalBits) / rhs._value);
    return result;   
}

// Pre-incrementation operations
Fixed& Fixed::operator++()
{
    _value += 1;
    return *this;
}

Fixed& Fixed::operator--()
{
    _value -= 1;
    return *this;
}

// post-incrementatino operations
Fixed& Fixed::operator++( int )
{
    Fixed temp(*this);
    ++(*this);
    return temp;
}

Fixed Fixed::operator--( int )
{
    Fixed temp(*this);
    --(*this);
    return temp;
}

// min max functions
Fixed Fixed::min(Fixed& a, Fixed& b)
{
    if (a < b)
        return (a);
    return (b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    if (a > b)
        return (a);
    return (b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    if (a < b)
        return (a);
    return (b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    if (a > b)
        return (a);
    return (b);
}


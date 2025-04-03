/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hali-mah <hali-mah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 11:20:16 by hali-mah          #+#    #+#             */
/*   Updated: 2025/04/03 11:36:09 by hali-mah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    private:
    int               _value;
    static const int  _fractionalBits = 8;

    public:
    Fixed();
    Fixed(const int n);
    Fixed(const float n);
    Fixed(const Fixed& src);
    Fixed& operator=(const Fixed& rhs);
    ~Fixed();

    int     getRawBits( void ) const;
    void    setRawBits(int const raw);
    float   toFloat( void ) const;
    int     toInt( void ) const;


    //Bool operations
    bool operator>(const Fixed& rhs) const;
    bool operator<(const Fixed& rhs) const;
    bool operator>=(const Fixed& rhs) const;
    bool operator<=(const Fixed& rhs) const;
    bool operator==(const Fixed& rhs) const;
    bool operator!=(const Fixed& rhs) const;

    //Arethmetic operations
    Fixed operator+(const Fixed& rhs);
    Fixed operator-(const Fixed& rhs);
    Fixed operator*(const Fixed& rhs);
    Fixed operator/(const Fixed& rhs);

    //Incrementation decrementation operators
    
    friend std::ostream& operator<<(std::ostream& os, const Fixed& fixed);    
};

#endif
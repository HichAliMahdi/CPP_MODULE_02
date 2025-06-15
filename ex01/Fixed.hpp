/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hali-mah <hali-mah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 10:49:06 by hali-mah          #+#    #+#             */
/*   Updated: 2025/06/15 21:56:08 by hali-mah         ###   ########.fr       */
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
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
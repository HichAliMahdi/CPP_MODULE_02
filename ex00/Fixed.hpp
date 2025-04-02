/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hali-mah <hali-mah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:26:00 by hali-mah          #+#    #+#             */
/*   Updated: 2025/04/02 15:33:28 by hali-mah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
    private:
        int                 _value;
        static const int    _fractionalBits = 8;
        
    public:
        Fixed();                                // Default constructor
        Fixed(const Fixed& src);                // Copy constructor
        Fixed& operator=(const Fixed& rhs);     // Copy assignment operator
        ~Fixed();                               // Destructor

        int     getRawBits( void ) const;
        void    setRawBits(int const raw);
};

#endif
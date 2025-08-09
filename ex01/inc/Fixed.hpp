/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 19:08:45 by barjimen          #+#    #+#             */
/*   Updated: 2025/08/09 21:28:37 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <iostream>
class Fixed
{
private:
    int _value;
    static const int _bits = 8;
public:
//Forma canónica ortodoxa
    Fixed();
    //Constructor copia
    Fixed(const Fixed& other);
    //Asignación
    Fixed& operator=(const Fixed& other);
    ~Fixed();

    //Nuevos contructore requeridos por el subject
    Fixed(const int intValue);
    Fixed(const float floatValue);
    
    //Conversión
    float toFloat(void) const;
    float toInt(void) const;

    //Required methods
    int getRawBits(void) const;
    void setRawBits(int const raw);
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

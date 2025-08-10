/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 19:08:45 by barjimen          #+#    #+#             */
/*   Updated: 2025/08/10 18:06:36 by barjimen         ###   ########.fr       */
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

    //Comparadores:
    //1. Comparación
    bool operator>(const Fixed& other) const;
    bool operator<(const Fixed& other) const;
    bool operator>=(const Fixed& other) const;
    bool operator<=(const Fixed& other) const;
    bool operator==(const Fixed& other) const;
    bool operator!=(const Fixed& other) const;
    //2. Aritmeticos
    Fixed operator+(const Fixed& other) const;
    Fixed operator-(const Fixed& other) const;
    Fixed operator*(const Fixed& other) const;
    Fixed operator/(const Fixed& other) const;
    //3. Incrementación
    Fixed& operator++();
    Fixed operator++(int);
    Fixed& operator--();
    Fixed operator--(int);
    //4. Max / Min
    static Fixed& min(Fixed& a, Fixed& b);
    static const Fixed& min(const Fixed& a,const Fixed& b);
    static Fixed& max(Fixed& a, Fixed& b);
    static const Fixed& max(const Fixed& a,const Fixed& b);
    
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

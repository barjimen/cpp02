/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 19:09:10 by barjimen          #+#    #+#             */
/*   Updated: 2025/08/09 21:48:31 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"
# include <cmath>
//Default constructor
Fixed::Fixed() : _value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

//Constructor copy
Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

//Asigne operator
Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Assignment operator called" << std::endl;
    if (this != &other)
        this->_value = other.getRawBits();
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Default destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    //std::cout << "getRawBits function called" << std::endl;
    return this->_value;
}

void Fixed::setRawBits(int const raw)
{
    //std::cout << "setRawBits function called" << std::endl;
    this->_value = raw;
}

//We use this to access the atributte of the actual objet (_value)
// This is a pointer type of Fixed*ç
//Whitout this the compilator didnt know if _valu is a parameter or an atributte

//------------------------------ EX01 ------------------------------------------
//Constructor de int
Fixed::Fixed(const int intValue)
{
    std::cout << "Int constructor called" << std::endl;
    _value = intValue << _bits;
}
//En el caso de int:
//Valor int: 10
//Multiplicamos por 256  → 10 * 256 = 2560
//Binario (16 bits): 0000101000000000

//_value = 2560

//Constructor de float
Fixed::Fixed(const float floatValue)
{
    std::cout << "Float constructor called" << std::endl;
    _value = roundf(floatValue * (1 << _bits)); //Redondeamos con la función permitida
}
// En este caso funcionaria así:
//Si le dieramos de valor float: 42.42
//Multiplicamos por 256  → 42.42 * 256 ≈ 10859.52
//Redondeamos → 10860
//Binario: 0010101000111100
// Entonces value es:
//_value = 10860

//Ahora empezamos con las funciones de conversión
//Aqui hacemos lo mismo para dividirlo y volver a tener el mismo valor
float Fixed::toFloat(void) const
{
    return (float)_value / (1 << _bits);
}

float Fixed::toInt(void) const
{
    return _value >> _bits; //Dividimos por 256
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
    out << fixed.toFloat();
    return out;
}

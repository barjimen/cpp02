/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 19:09:10 by barjimen          #+#    #+#             */
/*   Updated: 2025/08/12 18:57:24 by barjimen         ###   ########.fr       */
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
//Constructor of int
Fixed::Fixed(const int intValue)
{
    std::cout << "Int constructor called" << std::endl;
    _value = intValue << _bits;
}
//int:
//Value int: 10
//Multiply por 256  → 10 * 256 = 2560
//Binary (16 bits): 0000101000000000

//_value = 2560

//Constructor of float
Fixed::Fixed(const float floatValue)
{
    std::cout << "Float constructor called" << std::endl;
    _value = roundf(floatValue * (1 << _bits)); //Rounded
}
// In this case:
//we give float: 42.42
//Multiply 256  → 42.42 * 256 ≈ 10859.52
//rounded → 10860
//Binary: 0010101000111100
//value is:
//_value = 10860

//Converst functions:
//We do the same but we / 256
float Fixed::toFloat(void) const
{
    return (float)_value / (1 << _bits);
}

float Fixed::toInt(void) const
{
    return _value >> _bits; //Divided by 256
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
    out << fixed.toFloat();
    return out;
}

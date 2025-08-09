/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 19:08:45 by barjimen          #+#    #+#             */
/*   Updated: 2025/08/09 20:58:51 by barjimen         ###   ########.fr       */
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
    Fixed();
    //Constructor copia
    Fixed(const Fixed& other);
    //Asignación
    Fixed& operator=(const Fixed& other);
    ~Fixed();

    //Required methods
    int getRawBits(void) const;
    void setRawBits(int const raw);
};
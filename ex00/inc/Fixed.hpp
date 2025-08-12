/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 19:08:45 by barjimen          #+#    #+#             */
/*   Updated: 2025/08/12 18:52:42 by barjimen         ###   ########.fr       */
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
//Orthodox Canonical Form
    //Create an object
    Fixed();
    //Constructor copy, create an objetc with data of another
    Fixed(const Fixed &other);
    //copy assignment, replace the content with other content
    Fixed &operator=(const Fixed &other);
    ~Fixed();

    //Required functions
    int getRawBits(void) const;
    void setRawBits(int const raw);
};
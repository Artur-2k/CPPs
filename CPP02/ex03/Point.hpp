/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artuda-s <artuda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:17:23 by artuda-s          #+#    #+#             */
/*   Updated: 2025/01/28 15:36:43 by artuda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include "Fixed.hpp"

class Point
{
    private:
        Fixed _x;
        Fixed _y;
    public:
        Point( void );
        Point( int x, int y );
        Point( float x, float y );
        Point(  const Point &other );
        ~Point( void );

        Fixed getX( void ) const;
        Fixed getY( void ) const;
        
        Point& operator = ( const Point &other );
};

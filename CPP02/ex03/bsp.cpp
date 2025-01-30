/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artuda-s <artuda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:51:47 by artuda-s          #+#    #+#             */
/*   Updated: 2025/01/28 15:35:06 by artuda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static double TriangleArea(const Point &v1, const Point &v2, const Point &v3)
{
    //  Determinant form
    // A = 1/2 * |x1(y2 - y3) + x2(y3 - y1) + x3 (y1 - y2)|
    double x1 = v1.getX().toFloat();
    double x2 = v2.getX().toFloat();
    double x3 = v3.getX().toFloat();
    double y1 = v1.getY().toFloat();
    double y2 = v2.getY().toFloat();
    double y3 = v3.getY().toFloat();
    double area = 1.0/2.0 * fabs(x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2));
    return area;
}
bool bsp(const Point &v1, const Point &v2, const Point &v3, const Point &p)
{
    // If the sum of the combination of every triangle with 
    // two vertices and the point is greater than the area of the 
    // original triangle then the point is outside. if it is the same then it is 
    // inside

    double totalArea = TriangleArea(v1, v2, v3);
    double area1 = TriangleArea(v1, v2, p);
    double area2 = TriangleArea(v1, v3, p);
    double area3 = TriangleArea(v2, v3, p);

    // What is happening
    {
    std::cout << "Total area = " << totalArea << std::endl;
    std::cout << "area1 = " << area1 << std::endl;
    std::cout << "area2 = " << area2 << std::endl;
    std::cout << "area3 = " << area3 << std::endl;
    std::cout << "area1 + area2 + area3 = " << area1 + area2 + area3 << std::endl;
    std::cout << "totalArea == area1 + area2 + area3 : " << (totalArea == area1 + area2 + area3 ? "true" : "false") << std::endl;
    }
    
    return ( totalArea == area1 + area2 + area3 );
}

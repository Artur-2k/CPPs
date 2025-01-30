#include "Fixed.hpp"
#include "Point.hpp"

bool bsp(const Point &v1, const Point &v2, const Point &v3, const Point &p);

int main()
{
    // Triangle vertices
    /*
  v3|     p
    |\
    L_\_________
  v1   v2
    */
    Point v1(0,0);
    Point v2(5,0);
    Point v3(0,5); 
    // Point to check
    Point p(10,10);

    if (bsp(v1, v2, v3, p))
        std::cout << "Point P1 is inside of the triangle" << std::endl;
    else
        std::cout << "Point P2 is outside of the triangle" << std::endl;

    p = Point(5,0); 
    std::cout << std::endl; 

    if (bsp(v1, v2, v3, p))
        std::cout << "Point P1 is inside of the triangle" << std::endl;
    else
        std::cout << "Point P2 is outside of the triangle" << std::endl;
    return 0;
}

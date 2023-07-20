#ifndef EX2_HPP
#define EX2_HPP
#include <iostream>

namespace myspace
{
    class Point_3D
    {
        public:
            Point_3D(int a, int b, int c) : x(a), y(b), z(c){};
            friend std::ostream& operator<<(std::ostream& os, const Point_3D& vect);
            friend Point_3D operator+(const Point_3D& v1, const Point_3D& v2);
            friend Point_3D operator-(const Point_3D& v1, const Point_3D& v2);
            Point_3D& operator+=(const Point_3D& v2);
            Point_3D& operator-=(const Point_3D& v2);
        private:
            int x;
            int y;
            int z;
    };

    /*
    **  Operator overloads
    */
    std::ostream& operator<<(std::ostream& os, const Point_3D& vect){
        os << vect.x << ',' << vect.y << ',' << vect.z << '\n';
        return os;
    }
    Point_3D& Point_3D::operator+=(const Point_3D& v2){
        x += v2.x;
        y += v2.y;
        z += v2.z;
        return *this;
    }
    Point_3D& Point_3D::operator-=(const Point_3D& v2){
        x -= v2.x;
        y -= v2.y;
        z -= v2.z;
        return *this;
    }
    Point_3D operator+(const Point_3D& v1, const Point_3D& v2){
        return {v1.x + v2.x, v1.y + v2.y, v1.z + v2.z};
    }
    Point_3D operator-(const Point_3D& v1, const Point_3D& v2){
        return {v1.x - v2.x, v1.y - v2.y, v1.z - v2.z};
    }
}

#endif

#ifndef EX2_HPP
#define EX2_HPP
#include <iostream>
#include <cstdlib>
#include <limits>

namespace myspace
{
    class Point_3D
    {
        public:
            int x;
            int y;
            int z;
            Point_3D() = default;
            Point_3D(int a, int b, int c) : x(a), y(b), z(c){};
            friend std::ostream& operator<<(std::ostream& os, const Point_3D& vect);
            friend Point_3D operator+(const Point_3D& v1, const Point_3D& v2);
            friend Point_3D operator-(const Point_3D& v1, const Point_3D& v2);
            Point_3D& operator+=(const Point_3D& v2);
            Point_3D& operator-=(const Point_3D& v2);
        private:
            const int legal_int(const int64_t& val) const;
            std::string to_string(const Point_3D& vect) const;
    }; 
}


#endif

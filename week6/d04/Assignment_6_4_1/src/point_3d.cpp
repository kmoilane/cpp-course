#include "../includes/point_3d.hpp"
#include <string>

namespace myspace
{
    /*
    **  Operator overloads
    */
    std::ostream& operator<<(std::ostream& os, const Point_3D& vect){
        os << vect.to_string(vect);
        return os;
    }
    Point_3D& Point_3D::operator+=(const Point_3D& v2){
        x = Point_3D::legal_int(static_cast<int64_t>(x) +
                                static_cast<int64_t>(v2.x));
        y = Point_3D::legal_int(static_cast<int64_t>(y) +
                                static_cast<int64_t>(v2.y));
        z = Point_3D::legal_int(static_cast<int64_t>(z) +
                                static_cast<int64_t>(v2.z));
        return *this;
    }
    Point_3D& Point_3D::operator-=(const Point_3D& v2){
        x = Point_3D::legal_int(static_cast<int64_t>(x) -
                                static_cast<int64_t>(v2.x));
        y = Point_3D::legal_int(static_cast<int64_t>(y) -
                                static_cast<int64_t>(v2.y));
        z = Point_3D::legal_int(static_cast<int64_t>(z) -
                                static_cast<int64_t>(v2.z));
        return *this;
    }
    Point_3D operator+(const Point_3D& v1, const Point_3D& v2){
        Point_3D point;
        return {point.legal_int(static_cast<int64_t>(v1.x) +
                                static_cast<int64_t>(v2.x)),
                point.legal_int(static_cast<int64_t>(v1.y) +
                                static_cast<int64_t>(v2.y)),
                point.legal_int(static_cast<int64_t>(v1.z) +
                                static_cast<int64_t>(v2.z))};
    }
    Point_3D operator-(const Point_3D& v1, const Point_3D& v2){
        Point_3D point;
        return {point.legal_int(static_cast<int64_t>(v1.x) -
                                static_cast<int64_t>(v2.x)),
                point.legal_int(static_cast<int64_t>(v1.y) -
                                static_cast<int64_t>(v2.y)),
                point.legal_int(static_cast<int64_t>(v1.z) -
                                static_cast<int64_t>(v2.z))};
    }

    /*
    **  If val is over max int size, returns max int, if under min int size
    **  returns min int, else returns val
    */
     const int Point_3D::legal_int(const int64_t& val) const {
        if (val >= std::numeric_limits<int>::max())
            return std::numeric_limits<int>::max();
        else if (val <= std::numeric_limits<int>::min())
            return std::numeric_limits<int>::min();
        return static_cast<int>(val);      
    }

    std::string Point_3D::to_string(const Point_3D& vect) const
    {
        return '[' + std::to_string(vect.x) + ',' + std::to_string(vect.y) + ','
                + std::to_string(vect.y) + "]\n";
    }

}

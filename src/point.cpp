#include "Point.hpp"
#include <cmath>

Point::Point(double x, double y) : xCoord{x}, yCoord{y} {}

double Point::operator-(const Point& other) const {
    double dx = xCoord - other.xCoord;
    double dy = yCoord - other.yCoord;
    return std::sqrt(dx*dx + dy*dy);
}

Point Point::operator/(const Point& other) const {
    return Point((xCoord + other.xCoord)/2, (yCoord + other.yCoord)/2);
}
bool Point::operator==(const Point& other) const {
    return xCoord == other.xCoord && yCoord == other.yCoord;
}
bool Point::operator!=(const Point& other) const {
    return xCoord != other.xCoord || yCoord != other.yCoord;
}

Point Point::operator*(const double constant) const {
    return Point(xCoord * constant, yCoord * constant);
}

double Point::operator[](const char axis) const {
   if (axis == 'x') {
       return xCoord;
   }
    else if (axis == 'y') {
        return yCoord;
    }
}
std::ostream& operator<<(std::ostream& os, const Point& p) {
    os << "(" << p.xCoord << ", " << p.yCoord << ")";
    return os;
}


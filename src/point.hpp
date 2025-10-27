#pragma once

#include <iostream>

class Point {
public:
    double xCoord{};
    double yCoord{};

    Point(double x, double y);

    double operator-(const Point& other) const;

    Point operator/(const Point& other) const;

    bool operator==(const Point& other) const;
    bool operator!=(const Point& other) const;
    Point operator*(const double constant) const;
    double operator[](const char axis) const;
};

std::ostream& operator<<(std::ostream& os, const Point& p);

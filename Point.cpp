#include "Point.h"

// Инициализация статической переменной
unsigned int Point::max_coord = 1000;

Point::Point(unsigned int x, unsigned int y) {
    setX(x);
    setY(y);
}

void Point::setMaxCoord(unsigned int max) {
    max_coord = max;
}

void Point::setX(unsigned int x) {
    if (x > max_coord) {
        throw std::out_of_range("X coordinate exceeds maximum value");
    }
    this->x = x;
}

void Point::setY(unsigned int y) {
    if (y > max_coord) {
        throw std::out_of_range("Y coordinate exceeds maximum value");
    }
    this->y = y;
}

bool Point::operator==(const Point& other) const {
    return x == other.x && y == other.y;
}

std::ostream& operator<<(std::ostream& os, const Point& p) {
    os << "(" << p.x << "," << p.y << ")";
    return os;
}

std::istream& operator>>(std::istream& is, Point& p) {
    char ch;
    is >> ch >> p.x >> ch >> p.y >> ch;
    if (p.x > Point::max_coord || p.y > Point::max_coord) {
        is.setstate(std::ios::failbit);
    }
    return is;
}

#include "Oval.h"
#include <sstream>

Oval::Oval(const Point& center, unsigned int a, unsigned int b) 
    : center(center), a(a), b(b) {
    if (a == 0 || b == 0) {
        throw std::invalid_argument("Axes cannot be zero");
    }
}

std::string Oval::toString() const {
    std::ostringstream oss;
    oss << "Oval(Center: " << center << ", A: " << a << ", B: " << b << ")";
    return oss.str();
}

void Oval::readFromStream(std::istream& is) {
    Point c;
    unsigned int a, b;
    is >> c >> a >> b;
    *this = Oval(c, a, b);
}

double Oval::getArea() const {
    return M_PI * a * b;
}

double Oval::getPerimeter() const {
    double h = pow(a - b, 2) / pow(a + b, 2);
    return M_PI * (a + b) * (1 + (3 * h) / (10 + sqrt(4 - 3 * h)));
}

bool Oval::contains(const Point& point) const {
    double dx = point.getX() - center.getX();
    double dy = point.getY() - center.getY();
    return (dx*dx)/(a*a) + (dy*dy)/(b*b) <= 1;
}

std::string Oval::toString(const Oval& oval) {
    return oval.toString();
}

Oval Oval::fromStream(std::istream& is) {
    Oval oval;
    is >> oval;
    return oval;
}

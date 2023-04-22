#include "Vec3.hpp"

Vec3::Vec3(double x, double y, double z) : x(x), y(y), z(z) {}

double Vec3::get_x() const {
    return this->x;
}

double Vec3::get_y() const {
    return this->y;
}

double Vec3::get_z() const {
    return this->z;
}

Vec3 Vec3::operator*(double scalar) const {
    return {scalar * this->x, scalar * this->y, scalar * this->z};
}

Vec3 Vec3::operator-() const {
    return *this * -1;
}

Vec3 Vec3::operator+(Vec3 other) const {
    return {this->x + other.get_x(), this->y + other.get_y(), this->z + other.get_z()};
}

Vec3 Vec3::operator-(Vec3 other) const {
    return *this + -other;
}

double Vec3::dot(Vec3 other) const {
    return this->x * other.get_x() + this->y * other.get_y() + this->z * other.get_z();
}

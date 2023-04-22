#ifndef CGFROMSCRATCH_VEC3_HPP
#define CGFROMSCRATCH_VEC3_HPP


#include <cstddef>
#include <array>

class Vec3 {
public:
    Vec3(double x, double y, double z);

    [[nodiscard]] double get_x() const;

    [[nodiscard]] double get_y() const;

    [[nodiscard]] double get_z() const;

    Vec3 operator*(double scalar) const;

    Vec3 operator-() const;

    Vec3 operator+(Vec3 other) const;

    Vec3 operator-(Vec3 other) const;

    double dot(Vec3 other) const;

private:
    double x, y, z;
};


#endif //CGFROMSCRATCH_VEC3_HPP

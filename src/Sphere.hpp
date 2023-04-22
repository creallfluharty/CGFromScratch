#ifndef CGFROMSCRATCH_SPHERE_HPP
#define CGFROMSCRATCH_SPHERE_HPP


#include "Vec3.hpp"
#include "Color.hpp"

#include <list>

class Sphere {
public:
    Sphere(Color color, Vec3 position, double radius);

    std::list<double> get_ray_intersection(Vec3 ray) const;

    [[nodiscard]] Color get_color() const;

    [[nodiscard]] Vec3 get_pos() const;

    [[nodiscard]] double get_radius() const;

private:
    Color color;
    Vec3 position;
    double radius;
};


#endif //CGFROMSCRATCH_SPHERE_HPP

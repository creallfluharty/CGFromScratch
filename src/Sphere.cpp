#include "Sphere.hpp"

#include <cmath>

Sphere::Sphere(Color color, Vec3 position, double radius) : color(color), position(position), radius(radius) {}

std::list<double> Sphere::get_ray_intersection(Vec3 ray) const {
    auto a = ray.dot(ray);
    auto b = 2 * this->position.dot(ray);
    auto c = this->position.dot(this->position) - this->radius * this->radius;

    auto discriminate = b*b - 4*a*c;

    if (discriminate < 0)
        return {};

    if (discriminate == 0)
        return {-b / (2 * a)};

    auto t1 = (-b + std::sqrt(discriminate)) / (2 * a);
    auto t2 = (-b - std::sqrt(discriminate)) / (2 * a);

    return {t1, t2};
}

Color Sphere::get_color() const {
    return this->color;
}

Vec3 Sphere::get_pos() const {
    return this->position;
}

double Sphere::get_radius() const {
    return this->radius;
}

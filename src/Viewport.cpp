#include "Viewport.hpp"

Viewport::Viewport(int32_t width, int32_t height, int32_t z) : width(width), height(height), z(z) {}

Vec3 Viewport::get_ray(double x, double y) const {
    return {this->width * x, this->height * y, static_cast<double>(this->z)};
}

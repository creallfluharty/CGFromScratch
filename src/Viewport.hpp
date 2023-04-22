#ifndef CGFROMSCRATCH_VIEWPORT_HPP
#define CGFROMSCRATCH_VIEWPORT_HPP


#include <cstdint>
#include "Vec3.hpp"

class Viewport {
public:
    Viewport(int32_t width, int32_t height, int32_t z);

    [[nodiscard]] Vec3 get_ray(double x, double y) const;

private:
    int32_t width, height;
    int32_t z;
};


#endif //CGFROMSCRATCH_VIEWPORT_HPP

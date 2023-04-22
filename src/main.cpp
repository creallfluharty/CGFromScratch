#include <iostream>
#include <cmath>

#include <SDL.h>
#include <optional>

#include "Canvas.hpp"
#include "Sphere.hpp"
#include "Viewport.hpp"


namespace Colors {
    auto const RED = Color(255, 0, 0);
    auto const GREEN = Color(0, 255, 0);
    auto const BLUE = Color(0, 0, 255);
    auto const BLACK = Color(0, 0, 0);
}


std::optional<Color> get_color(const std::vector<Sphere>& spheres, const Vec3& ray);


int main(int argc, char** argv) {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        throw std::runtime_error(SDL_GetError());
    }

    auto canvas = Canvas(256, 256);
    auto viewport = Viewport(1, 1, 1);

    auto spheres = std::vector<Sphere> {
        {Colors::RED, {0, -1, 3}, 1},
        {Colors::GREEN, {2, 0, 4}, 1},
        {Colors::BLUE, {-2, 0, 4}, 1},
    };

    bool window_should_close = false;

    while (!window_should_close) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) window_should_close = true;
        }

        canvas.clear(Colors::BLACK);

        for (auto y = canvas.get_bottom(); y <= canvas.get_top(); ++y) {
            for (auto x = canvas.get_left(); x <= canvas.get_right(); ++x) {
                auto s = static_cast<double>(x) / canvas.get_width();
                auto t = static_cast<double>(y) / canvas.get_height();

                auto ray = viewport.get_ray(s, t);
                auto color = get_color(spheres, ray);
                if (color.has_value())
                    canvas.put_pixel(
                        x,
                        y,
                        color.value()
                    );
            }
        }
        canvas.display();
        SDL_Delay(100);
    }

    SDL_Quit();
    return 0;
}

std::optional<Color> get_color(const std::vector<Sphere>& spheres, const Vec3& ray) {
    auto color = std::optional<Color>();
    auto closest_t = std::numeric_limits<double>::infinity();

    for (auto& sphere : spheres)
        for (auto& t : sphere.get_ray_intersection(ray))
            if (t < closest_t)
                color.emplace(sphere.get_color());

    return color;
}

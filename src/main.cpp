#include <iostream>
#include <cmath>

#include <SDL.h>

#include "Canvas.hpp"


int main(int argc, char** argv) {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        throw std::runtime_error(SDL_GetError());
    }

    auto canvas = Canvas(256, 256);

    // canvas.clear(Color(255, 255, 0));

    bool window_should_close = false;

    while (!window_should_close) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) window_should_close = true;
        }

        for (auto y = canvas.get_bottom(); y <= canvas.get_top(); ++y) {
            for (auto x = canvas.get_left(); x <= canvas.get_right(); ++x) {
                canvas.put_pixel(
                    x,
                    y,
                    Color(1, 0, 0) * (x - canvas.get_left()) + Color(0, 1, 0) * (y - canvas.get_bottom())
                );
            }
        }
        canvas.display();
        SDL_Delay(100);
    }

    SDL_Quit();
    return 0;
}
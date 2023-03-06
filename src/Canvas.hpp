#ifndef CANVAS_HPP
#define CANVAS_HPP

#include <memory>
#include <functional>

#include <SDL.h>
#include "Color.hpp"

class Canvas {
public:
    Canvas(uint32_t width, uint32_t height);

    void put_pixel(int32_t x, int32_t y, Color color);
    void clear(Color color);
    void display();

    [[nodiscard]] uint32_t get_width() const;
    [[nodiscard]] uint32_t get_height() const;

    [[nodiscard]] int32_t get_left() const;
    [[nodiscard]] int32_t get_right() const;
    [[nodiscard]] int32_t get_bottom() const;
    [[nodiscard]] int32_t get_top() const;

private:
    uint32_t width, height;
    int32_t x_offset, y_offset;
    std::unique_ptr<SDL_Window, std::function<void(SDL_Window*)>> window;
    std::unique_ptr<SDL_Renderer, std::function<void(SDL_Renderer*)>> renderer;
};

#endif
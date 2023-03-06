#include <stdexcept>

#include "Canvas.hpp"


Canvas::Canvas(uint32_t width, uint32_t height) :
    width(width),
    height(height),
    x_offset(-static_cast<int32_t>(width / 2)),
    y_offset(-static_cast<int32_t>(height / 2)),
    window(
        SDL_CreateWindow(
            "CGFromScratch",
            SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
            static_cast<int>(width), static_cast<int>(height),
            0
        ),
        SDL_DestroyWindow
    ),
    renderer(
        SDL_CreateRenderer(this->window.get(), -1, 0),
        SDL_DestroyRenderer
    ) {
        if (!this->window) {
            throw std::runtime_error(SDL_GetError());
        }

        if (!this->renderer) {
            throw std::runtime_error(SDL_GetError());
        }
    }

void Canvas::put_pixel(int32_t x, int32_t y, Color color) {
    if (this->get_left() > x || x > this->get_right() || this->get_bottom() > y || y > this->get_top())
        throw std::out_of_range("Pixel location out of range.");
    
    SDL_SetRenderDrawColor(this->renderer.get(), color.get_red(), color.get_green(), color.get_blue(), Color::get_channel_max());

    SDL_RenderDrawPoint(this->renderer.get(), x - this->x_offset, -y - this->y_offset);
}

void Canvas::clear(Color color) {
    SDL_SetRenderDrawColor(this->renderer.get(), color.get_red(), color.get_green(), color.get_blue(), Color::get_channel_max());
    SDL_RenderClear(this->renderer.get());
}

void Canvas::display() {
    SDL_RenderPresent(this->renderer.get());
}

uint32_t Canvas::get_width() const { return this->width; }

uint32_t Canvas::get_height() const { return this->height; }

int32_t Canvas::get_left() const { return this->x_offset; }

int32_t Canvas::get_right() const { return this->width + this->x_offset - 1; }

int32_t Canvas::get_bottom() const { return this->y_offset; }

int32_t Canvas::get_top() const { return this->height + this->y_offset - 1; }
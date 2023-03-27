#ifndef COLOR_HPP
#define COLOR_HPP

#include <cstdint>
#include <iostream>

class Color {
public:
    Color(uint8_t red, uint8_t green, uint8_t blue);

    static uint8_t get_channel_max();

    [[nodiscard]] uint8_t get_red() const;

    [[nodiscard]] uint8_t get_green() const;

    [[nodiscard]] uint8_t get_blue() const;

    Color operator*(double k) const;

    Color operator+(Color other) const;

private:
    uint8_t red, green, blue;
};

std::ostream& operator<<(std::ostream& out, const Color& color);

#endif
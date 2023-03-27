#include <algorithm>
#include <limits>

#include "Color.hpp"

Color::Color(uint8_t red, uint8_t green, uint8_t blue) : red(red), green(green), blue(blue) {}

uint8_t Color::get_channel_max() {
    return std::numeric_limits<uint8_t>::max();
}

uint8_t Color::get_red() const { return red; }

uint8_t Color::get_green() const { return green; }

uint8_t Color::get_blue() const { return blue; }

Color Color::operator*(double k) const {
    return {
        static_cast<uint8_t>(std::clamp<double>(this->red * k, 0, this->get_channel_max())),
        static_cast<uint8_t>(std::clamp<double>(this->green * k, 0, this->get_channel_max())),
        static_cast<uint8_t>(std::clamp<double>(this->blue * k, 0, this->get_channel_max()))
    };
}

Color Color::operator+(Color other) const {
    return {
        static_cast<uint8_t>(std::clamp<uint16_t>(this->red + other.get_red(), 0, this->get_channel_max())),
        static_cast<uint8_t>(std::clamp<uint16_t>(this->green + other.get_green(), 0, this->get_channel_max())),
        static_cast<uint8_t>(std::clamp<uint16_t>(this->blue + other.get_blue(), 0, this->get_channel_max()))
    };
}

std::ostream& operator<<(std::ostream& out, const Color& color) {
    return out << "Color(" << +color.get_red() << ", " << +color.get_green() << ", " << +color.get_blue() << ")";
}
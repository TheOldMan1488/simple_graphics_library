#pragma once
#include <tuple>


struct Color
{
    Color(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha = 255);
    std::tuple<float, float, float, float> getGlValue() const;

    unsigned char red, green, blue, alpha;
};
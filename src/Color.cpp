#include <Color.h>


Color::Color(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha) : red(red), green(green), blue(blue), alpha(alpha)
{
}

std::tuple<float, float, float, float> Color::getGlValue() const
{
    float glRed = this->red / 255.f;
    float glGreen = this->green / 255.f;
    float glBlue = this->blue / 255.f;
    float glAlpha = this->alpha / 255.f;

    return std::tuple<float, float, float, float>(glRed, glGreen, glBlue, glAlpha);
}
#include "Color.hpp"

Color::Color(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha)
{
    this->red = red;
    this->green = green;
    this->blue = blue;
    this->alpha = alpha;

    colorArray[0] = red;
    colorArray[1] = green;
    colorArray[2] = blue;
    colorArray[3] = alpha;
}

void Color::setRGB(unsigned char red, unsigned char green, unsigned char blue)
{
    this->red = red;
    this->green = green;
    this->blue = blue;

    colorArray[0] = red;
    colorArray[1] = green;
    colorArray[2] = blue;
}

void Color::setRGBA(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha)
{
    this->red = red;
    this->green = green;
    this->blue = blue;
    this->alpha = alpha;

    colorArray[0] = red;
    colorArray[1] = green;
    colorArray[2] = blue;
    colorArray[3] = alpha;
}

void Color::setRed(unsigned char red)
{
    this->red = red;
    colorArray[0] = red;
}

void Color::setGreen(unsigned char green)
{
    this->green = green;
    colorArray[1] = green;
}

void Color::setBlue(unsigned char blue)
{
    this->blue = blue;
    colorArray[2] = blue;
}

void Color::setAlpha(unsigned char alpha)
{
    this->alpha = alpha;
    colorArray[3] = alpha;
}

unsigned char Color::getRed() { return red; }
unsigned char Color::getGreen() { return green; }
unsigned char Color::getBlue() { return blue; }
unsigned char Color::getAlpha() { return alpha; }
unsigned char *Color::getColorArray() { return colorArray; }
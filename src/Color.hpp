#ifndef _COLOR_HPP_
#define _COLOR_HPP_

class Color
{
    unsigned char red, green, blue, alpha;
    unsigned char colorArray[4];

  public:
    Color(unsigned char red = 0, unsigned char green = 0, unsigned char blue = 0,
          unsigned char alpha = 0);

    void setRGB(unsigned char red, unsigned char green, unsigned char blue);
    void setRGBA(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha);
    void setRed(unsigned char red);
    void setGreen(unsigned char green);
    void setBlue(unsigned char blue);
    void setAlpha(unsigned char alpha);
    unsigned char getRed();
    unsigned char getGreen();
    unsigned char getBlue();
    unsigned char getAlpha();
    unsigned char *getColorArray();
};

#endif

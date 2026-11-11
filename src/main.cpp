#include "tga.h"


constexpr TGAColor white { 255, 255, 255 };
constexpr TGAColor red { 255, 0, 0 };
constexpr TGAColor blue { 0, 0, 255 };
constexpr TGAColor green { 0, 255, 0 };
constexpr TGAColor yellow { 255, 255, 0 };

int main()
{   
    Point a{ 7, 3 };
    // Point b{ 12, 37 };
    Point b{ 62, 3 };
    Point c{ 62, 53 };
    TGAImage image{ 64, 64 };

    image.set(a, white);
    image.set(b, blue);
    image.set(c, red);
    image.line(a, b, blue);
    image.line(c, b, green);
    image.line(c, a, yellow);
    image.line(a, c, red);
    image.writeTgaFile();
}

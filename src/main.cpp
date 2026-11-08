#include "tga.h"
#include <iostream>


constexpr TGAColor white { 255, 255, 255 };
constexpr TGAColor red { 255, 0, 0 };
constexpr TGAColor blue { 0, 0, 255 };

int main()
{   
    std::cout << "Hello, world!\n";
    TGAImage image{ 64, 64 };
    image.set(7, 3, white);
    image.set(12, 37, blue);
    image.set(62, 53, red);
    image.writeTgaFile();
}

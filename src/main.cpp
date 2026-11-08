#include "tga.h"
#include <iostream>

int main()
{   
    std::cout << "Hello, world!\n";
    TGAImage image{ 64, 64 };
    image.writeTgaFile();
}

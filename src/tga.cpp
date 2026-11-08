#include <array>
#include <cstdint>
#include <fstream>
#include <iostream>
#include "tga.h"

TGAImage::TGAImage(std::uint16_t width, std::uint16_t height)
    : m_width { width }, m_height { height }, m_framebuffer (width * height * 3)
{
}

void TGAImage::writeTgaFile()
{
    std::ofstream outf{ "framebuffer.tga", std::ios::binary };
    if (!outf)
    {
        std::cerr << "Uh oh, framebuffer.tga could not be opened for writing!\n";
    }

    std::array<unsigned char, 18> header{};

    header[2] = 2; // Image type = uncompressed true-color
    header[12] = m_width & 0x00FF; // Image width (2 bytes)
    header[13] = (m_width & 0xFF00) >> 8;
    header[14] = m_height & 0x00FF; // Image height (two bytes)
    header[15] = (m_height & 0xFF00) >> 8;
    header[16] = 24; // 24 bits per pixel
                     
    outf.write(reinterpret_cast<char*>(header.data()), sizeof(header));
    outf.write(
            reinterpret_cast<const char*>(m_framebuffer.data()),
            sizeof(std::uint8_t) * m_width * m_height * 3
    );
    return;
}

#include <array>
#include <cstdint>
#include <cmath>
#include <fstream>
#include <iostream>
#include "tga.h"

TGAImage::TGAImage(std::uint16_t width, std::uint16_t height)
    : m_width { width }, m_height { height }, m_framebuffer (width * height * 3)
{
}

void TGAImage::set(Point p, TGAColor color)
{
    int index = { ((p.y * m_width) + p.x) * 3 };
    m_framebuffer[index] = color.b;
    m_framebuffer[index + 1] = color.g;
    m_framebuffer[index + 2] = color.r;
}

void TGAImage::line(Point p1, Point p2, TGAColor color)
{
    bool steep{ std::abs(p2.y - p1.y) > std::abs(p2.x - p1.x) };

    if (steep)
    {
        std::swap(p2.x, p2.y);
        std::swap(p1.x,p1.y);
    }

    if (p1.x > p2.x)
    {
        std::swap(p1, p2);
    }

    for (int x{p1.x}; x <= p2.x; x++)
    {
        double t = (x - p1.x) / static_cast<float>(p2.x - p1.x);
        int y{ static_cast<int>(p1.y + t * (p2.y - p1.y)) };
        set(steep ? Point{y,x} : Point{x, y}, color);
    }
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

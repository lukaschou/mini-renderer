#ifndef TGA_HPP
#define TGA_HPP

#include <cstdint>
#include <vector>

struct TGAColor
{
    int r{};
    int g{};
    int b{};
};

struct Point
{
    int x{};
    int y{};
};

class TGAImage
{
public:
    TGAImage(std::uint16_t width, std::uint16_t height);
    void writeTgaFile();
    void set(Point p, TGAColor color);
    void line(Point p1, Point p2, TGAColor);

private:
    std::uint16_t m_width{};
    std::uint16_t m_height{};
    std::vector<std::uint8_t> m_framebuffer;
};

#endif

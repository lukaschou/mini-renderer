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

class TGAImage
{
public:
    TGAImage(std::uint16_t width, std::uint16_t height);
    void writeTgaFile();
    void set(int x, int y, TGAColor color);

private:
    std::uint16_t m_width{};
    std::uint16_t m_height{};
    std::vector<std::uint8_t> m_framebuffer;
};

#endif

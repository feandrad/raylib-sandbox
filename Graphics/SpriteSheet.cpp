#include "SpriteSheet.h"

#include "ImageUtils.h"
#include "raylib.h"

#include <cassert>
#include <iostream>

namespace Sandbox
{
    SpriteSheet::SpriteSheet(const std::filesystem::path &path)
    {
        if (!std::filesystem::exists(path))
        {
            std::cerr << "Sprite sheet doesn't exist! " << path << std::endl;
            // assert(false);
            return;
        }

        m_ImageBuffer = Utils::LoadImageBuffer(path, m_Width, m_Height);
    }

    SpriteSheet::SpriteSheet(SpriteSheet &&other)
    {
        if (&other == this)
            return;

        m_ImageBuffer = other.m_ImageBuffer;
        m_Width = other.m_Width;
        m_Height = other.m_Height;
        other.m_ImageBuffer = nullptr;
    }

    SpriteSheet &SpriteSheet::operator=(SpriteSheet &&other)
    {
        m_ImageBuffer = other.m_ImageBuffer;
        m_Width = other.m_Width;
        m_Height = other.m_Height;
        other.m_ImageBuffer = nullptr;
        return *this;
    }

    SpriteSheet::~SpriteSheet()
    {
        delete[] m_ImageBuffer;
    }
}
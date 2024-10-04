#pragma once

#include "raylib.h"

#include <map>
#include <cinttypes>

namespace Sandbox
{

    class Renderer
    {
    public:
        Renderer(int width, int height);
        ~Renderer();

        void Init();
        void Update();

        void ClearRandom();

        const Texture2D &GetTexture() const { return m_Texture; }

    private:
        int m_Width = 0;
        int m_Height = 0;

        int m_ViewOffsetX = 0, m_ViewOffsetY = 0;

        uint32_t *m_ImageBuffer = nullptr;
        Image m_Image;
        Texture2D m_Texture;
        // SpriteSheet m_SpriteSheet;
        std::map<int, Font> m_Fonts, m_BoldFonts;
    };
}
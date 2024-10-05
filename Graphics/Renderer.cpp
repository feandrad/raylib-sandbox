#include "Renderer.h"

#include "../Random.h"

namespace Sandbox
{
    Renderer::Renderer(int width, int height) : m_Width(width), m_Height(height)
    {
        m_ImageBuffer = new uint32_t[width * height];
    }

    void Renderer::Init()
    {
        m_SpriteSheet = SpriteSheet("../res/sprites/items.png");

        m_Image = GenImageColor(m_Width, m_Height, GetColor(0xff00ffff));
        m_Texture = LoadTextureFromImage(m_Image);
    }

    void Renderer::Update()
    {
        UpdateTexture(m_Texture, m_ImageBuffer);
    }

    void Renderer::ClearRandom()
    {
        for (uint32_t i = 0; i < m_Width * m_Height; i++)
        {
            int random = Random::UInt();
            random |= (0xff << 24);
            m_ImageBuffer[i] = random;
        }
    }

    void Renderer::SetViewOffset(int x, int y)
    {
        m_ViewOffsetX = x;
        m_ViewOffsetY = y;
    }

    void Renderer::RenderSpriteSheet(int x, int y)
    {
        x -= m_ViewOffsetX;
        y -= m_ViewOffsetY;

        uint32_t *spriteSheetBuffer = m_SpriteSheet.GetImageBuffer();
        for (int j = 0; j < m_SpriteSheet.GetHeight(); j++)
        {
            for (int i = 0; i < m_SpriteSheet.GetWidth(); i++)
            {
                int xLocal = i + x;
                int yLocal = j + y;
                if (xLocal < m_Width && yLocal < m_Height)
                {
                    int color = spriteSheetBuffer[i + j * m_SpriteSheet.GetWidth()];
                    if (color != 0x00000000)
                        m_ImageBuffer[xLocal + yLocal * m_Width] = color;
                }
            }
        }
    }

    Renderer::~Renderer()
    {
        delete[] m_ImageBuffer;
    }
}
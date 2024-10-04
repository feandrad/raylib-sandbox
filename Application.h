#pragma once

#include "Graphics/Renderer.h"

#include <string>

// #include "Graphics/Renderer.h"

namespace Sandbox
{
    struct ApplicationSpecification
    {
        int Width = 320;
        int Height = Width / 16 * 9;
        int Scale = 4;
        std::string Title = "Sandbox";
    };

    class Application
    {
    public:
        Application(const ApplicationSpecification &spec = ApplicationSpecification());
        ~Application();

        void Run();
        void OnUpdate();
        void OnRender();

    private:
        void Loop();
        // static void StaticLoop();

    private:
        ApplicationSpecification m_Specification;
        Renderer m_Renderer;
        // std::unique_ptr<Game> m_Game;

        double m_LastTime;

        // Image m_Icon;
        float m_Time = 0.0f;
    };
}

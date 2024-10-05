#include "raylib.h"
#include "Application.h"

#if defined(PLATFORM_WEB)
#include <emscripten/emscripten.h>
#endif

namespace Sandbox
{

    static Application *s_Instance = nullptr;

    Application::Application(const ApplicationSpecification &spec)
        : m_Specification(spec), m_Renderer(spec.Width, spec.Height)
    {
        s_Instance = this;
    }

    Application::~Application()
    {
        s_Instance = nullptr;
    }

    void Application::Run()
    {
        InitWindow(
            m_Specification.Width * m_Specification.Scale,
            m_Specification.Height * m_Specification.Scale,
            m_Specification.Title.c_str());

        SetExitKey(0);
        // m_Icon = LoadImage("res/icon.png");
        // SetWindowIcon(m_Icon);

        SetTargetFPS(60);

        m_Renderer.Init();
        // m_Game = std::make_unique<Game>();
        m_LastTime = GetTime();

#if defined(PLATFORM_WEB)
        emscripten_set_main_loop(StaticLoop, 0, 1);
#else
        while (!WindowShouldClose())
        {
            Loop();
        }
#endif

        CloseAudioDevice();
        CloseWindow();
        // UnloadImage(m_Icon);
    }

    void Application::Loop()
    {
        OnUpdate();
        OnRender();
    }

    void Application::OnUpdate()
    {
    }

    void Application::OnRender()
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        m_Renderer.ClearRandom();
        // m_Renderer.RenderSprite(50, 50, Sprites::torch);

        // m_Game->Render();
        m_Renderer.RenderSpriteSheet(10, 10);
        m_Renderer.Update();
        DrawTextureEx(m_Renderer.GetTexture(), Vector2{0.0f, 0.0f}, 0, (float)m_Specification.Scale, WHITE);
        // m_Game->RenderUI();

        EndDrawing();
    }
}
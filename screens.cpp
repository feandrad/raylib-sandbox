#include "screens.h"

Screen* ActiveScreen = nullptr;

void SetActiveScreen(Screen* screen)
{
	ActiveScreen = screen;
}

void DrawScreen()
{
	if (ActiveScreen != nullptr)
		ActiveScreen->Draw();
}

bool Screen::RectIsHovered(Rectangle& rect)
{
	return CheckCollisionPointRec(GetMousePosition(), rect);
}

void Screen::DrawCenteredText(int y, const char* text, int fontSize, Color color)
{
	int textWidth = MeasureText(text, fontSize);
	DrawText(text, GetScreenWidth() / 2 - textWidth / 2, y - fontSize / 2, fontSize, color);
}

bool Screen::CenteredButton(int y, const char* text)
{
	float rectHeight = ButtonFontSize + (ButtonBorder * 2.0f);
	float textWidth = float(MeasureText(text, ButtonFontSize));

	float textXOrigin = GetScreenWidth() / 2.0f - textWidth / 2.0f;
	float textYOrigin = y - ButtonFontSize / 2.0f;

	Rectangle buttonRect = { textXOrigin - ButtonBorder, textYOrigin - ButtonBorder, textWidth + (ButtonBorder * 2.0f), ButtonFontSize + (ButtonBorder * 2.0f) };

	bool hovered = RectIsHovered(buttonRect);
	bool down = hovered & IsMouseButtonDown(MOUSE_BUTTON_LEFT);

	Color color = hovered ? (down ? ButtonPressColor : ButtonHighlight) : (ButtonColor);

	DrawRectangleRec(buttonRect, ColorAlpha(color, 0.25f));
	DrawText(text, int(textXOrigin), int(textYOrigin), ButtonFontSize, color);
	DrawRectangleLinesEx(buttonRect, 2, color);

	bool clicked = hovered && IsMouseButtonPressed(MOUSE_BUTTON_LEFT);

	// if (clicked)
	// 	PlaySound(ClickSoundId);

	return clicked;
}

void Screen::DimScreen(float alpha)
{
	DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), ColorAlpha(BLACK, alpha));
}



    // class MainMenuScreen : public Screen
    // {
    // public:
    //     void Draw() override
    //     {
    //         DimScreen();

    //         DrawCenteredText(40, "Raylib Example", 40, BLUE);

    //         // version and copyright
    //         // DrawText(VersionString, 2, GetScreenHeight() - 10, 10, GRAY);
    //         // DrawText(CopyrightString, GetScreenWidth() - 2 - MeasureText(CopyrightString, 10), GetScreenHeight() - 10, 10, GRAY);

    //         if (CenteredButton(GetScreenHeight() / 4, "Play"))
    //             StartGame();

    //         CenteredButton(GetScreenHeight() / 2, "Options");

    //         if (CenteredButton(GetScreenHeight() - (GetScreenHeight() / 4), "Quit"))
    //             QuitApplication();
    //     }
    // };
    // MainMenuScreen MainMenu;

    // class GameOverScreen : public Screen
    // {
    // public:
    //     void Draw() override
    //     {
    //         DimScreen();

    //         DrawCenteredText(40, "Raylib RPG Example", 40, BLUE);

    //         if (IsWin)
    //             DrawCenteredText(120, "Congratulations You WON!", 60, WHITE);
    //         else
    //             DrawCenteredText(120, "You died, better luck next time.", 60, RED);

    //         DrawCenteredText(200, TextFormat("Score = %d", Gold), 60, YELLOW);

    //         // DrawText(VersionString, 2, GetScreenHeight() - 10, 10, GRAY);
    //         // DrawText(CopyrightString, GetScreenWidth() - 2 - MeasureText(CopyrightString, 10), GetScreenHeight() - 10, 10, GRAY);

    //         if (CenteredButton(GetScreenHeight() / 2, "Main Menu"))
    //             SetActiveScreen(&MainMenu);

    //         if (CenteredButton(GetScreenHeight() - (GetScreenHeight() / 4), "Quit"))
    //             QuitApplication();
    //     }

    //     bool IsWin = false;
    //     int Gold = 0;
    // };
    // GameOverScreen GameOver;
	
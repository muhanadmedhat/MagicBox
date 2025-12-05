#include "screen.h"


void showCursor(bool visible)
{
#ifdef _WIN32
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = visible;
    SetConsoleCursorInfo(hConsole, &cursorInfo);
#else
    std::cout << (visible ? "\033[?25h" : "\033[?25l") << std::flush;
#endif
}

void clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    std::cout << "\033[2J\033[H" << std::flush;
#endif
}

void gotoxy(int x, int y)
{
#ifdef _WIN32
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD CursorPosition;
    CursorPosition.X = x;
    CursorPosition.Y = y;
    SetConsoleCursorPosition(hConsole, CursorPosition);
#else
    std::cout << "\033[" << y + 1 << ";" << x + 1 << "H" << std::flush;
#endif
}

void setColor(int color)
{
#ifdef _WIN32
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
#else
    switch (color)
    {
    case 9:
        std::cout << "\033[94m";
        break;
    case 15:
        std::cout << "\033[97m";
        break;
    default:
        std::cout << "\033[0m";
        break;
    }
    std::cout << std::flush;
#endif
}
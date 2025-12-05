
#ifndef SCREEN_H
#define SCREEN_H
// --- Low-Level Console Function Declarations ---

#include <iostream>

#ifdef _WIN32
#include <windows.h> // For Windows API
#include <conio.h>   // For _getch()
#else
#include <unistd.h>  // For POSIX systems
#include <termios.h> // For terminal settings
#endif

void showCursor(bool visible);
void clearScreen();
void gotoxy(int x, int y);
void setColor(int color);

#endif // SCREEN_H
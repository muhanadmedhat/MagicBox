#include "magic.h"
#include <iostream>
#include <vector>
#include <string>

#ifdef _WIN32
#include <windows.h> // For Windows API
#include <conio.h>   // For _getch()
#else
#include <unistd.h>  // For POSIX systems
#include <termios.h> // For terminal settings
#endif
using namespace std;

// --- Low-Level Function Implementations ---

void showCursor(bool visible)
{
#ifdef _WIN32
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = visible;
    SetConsoleCursorInfo(hConsole, &cursorInfo);
#else
    cout << (visible ? "\033[?25h" : "\033[?25l") << flush;
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
    cout << "\033[" << y + 1 << ";" << x + 1 << "H" << flush;
#endif
}

void clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    cout << "\033[2J\033[H" << flush;
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
        cout << "\033[94m";
        break;
    case 15:
        cout << "\033[97m";
        break;
    default:
        cout << "\033[0m";
        break;
    }
    cout << flush;
#endif
}

// --- Magic Square Generator Implementation ---

void magicsquaregenerator(int n)
{
    while(n % 2 == 0 || n <= 0){
        clearScreen();
        gotoxy(10, 5);
        cout << "Grid size cannot be even number or string must be odd number. Please enter again the grid size: ";
        cin >> n;

        if(cin.fail()){
        cin.clear();              // Clear the error flag
        cin.ignore(10000, '\n');  // Discard invalid input from buffer
        n = 0;                    // Set n to invalid value to continue loop
    }
    }
    
    clearScreen();
    showCursor(false);
    
    // Display title
    gotoxy(10, 2);
    setColor(15);
    cout << "Magic Square Generator - Size: " << n << "x" << n;
    gotoxy(10, 3);
    cout << "Magic Sum: " << n * (n * n + 1) / 2;
    
    // Calculate spacing for display
    int cellWidth = 6;
    int startX = 10;
    int startY = 6;
    
    // Starting position: middle of top row
    int r = 0;
    int c = n / 2;
    
    // Generate and display magic square
    for (int cnt = 1; cnt <= n * n; cnt++)
    {
        // Display the number at current position
        gotoxy(startX + c * cellWidth, startY + r * 2);
        //gotoxy(c,r);
        setColor(15);
        cout << "[" << cnt << "]";
        
        // Delay for visual effect
        #ifdef _WIN32
            Sleep(600); 
        #else
            usleep(600000); 
        #endif
        
        // Calculate next position
        if (cnt % n == 0)
        {
            // Every nth number: move down one row
            r++;
        }
        else
        {
            // Regular move: diagonally up-right
            r--;
            c++;
        }
        
        // Wrap around boundaries
        if (r < 0)
            r = n - 1;
        if (r >= n)
            r = 0;
        if (c < 0)
            c = n - 1;
        if (c >= n)
            c = 0;
    }
    
    // Display completion message
    gotoxy(10, startY + n * 2 + 2);
    setColor(15);
    cout << "Magic Square Complete!";
    
}
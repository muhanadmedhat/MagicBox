#ifndef MAGIC_H
#define MAGIC_H

#include <string>
#include <vector>

// --- Key Code Definitions ---
#ifdef _WIN32
// Windows Virtual Key Codes
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_HOME 71
#define KEY_END 79
#else
// Linux ANSI Escape Sequences (final character)
#define KEY_UP 'A'
#define KEY_DOWN 'B'
#define KEY_RIGHT 'C'
#define KEY_LEFT 'D'
#define KEY_HOME 'H' // Or '1~'
#define KEY_END 'F'  // Or '4~'
#endif
#define KEY_ENTER 13
#define KEY_BACKSPACE 8 // ASCII code for Backspace
#define KEY_DELETE 127  // --- NEW: ASCII code for Delete ---

// --- Low-Level Console Function Declarations ---

void showCursor(bool visible);
void clearScreen();
void gotoxy(int x, int y);
void setColor(int color);
int readKey();

// --- High-Level Application Logic Declarations ---

void drawMenu(const std::vector<std::string> &items, int selectedItem);
void showMainMenu();
void handlePageInput();

void magicsquaregenerator(int n);
#endif // DRAW_H
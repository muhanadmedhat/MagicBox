#include "magic.h"


// --- Magic Square Generator Implementation ---

void magicsquaregenerator()
{
    int n = 0;
    string input;
    bool valid = false;
    
    while(!valid){
        clearScreen();
        gotoxy(10, 5);
        cout << "Enter grid size (must be odd number): ";
        
        getline(cin, input);
        
        // Check if input contains only digits
        bool allDigits = true;
        if(input.empty()){
            allDigits = false;
        }
        for(char c : input){
            if(!isdigit(c)){
                allDigits = false;
                break;
            }
        }
        
        if(allDigits){
            n = stoi(input);  // Convert string to integer
            if(n > 0 && n % 2 != 0){
                valid = true;  // Valid odd number
            }
        }
        if(n==1) valid=false;
        
        
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
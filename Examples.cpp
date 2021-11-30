#include "windows.h"
#include <iostream>
#include <conio.h>
void goToPositionInConsole(short x, short y)
{
    COORD coordinates; // Windows specific struct 
    coordinates.X = x;
    coordinates.Y = y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates); // Windows function
}
void toggleCursorVisibility(bool showCursor)
{
    HANDLE outputHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;

    cursorInfo.dwSize = 1;
    GetConsoleCursorInfo(outputHandle, &cursorInfo);
    cursorInfo.bVisible = showCursor;
    SetConsoleCursorInfo(outputHandle, &cursorInfo);

}

// Only the 0-15 represents character color. Above that you get background as well
void setColor(unsigned short color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void setConsoleSize(int x, int y)
{
    HWND console{ GetConsoleWindow() }; //HWND and GetConsoleWindow lies within the windows.h library
    RECT rect{};
    GetWindowRect(console, &rect); //Gets the current size of the console

    MoveWindow(console, rect.left, rect.top, x, y, true);
}

int main()
{
    toggleCursorVisibility(false);
    setConsoleSize(400, 400);

    int y{};
    int x{};
    //setColor(35);
    for (int i{}; i < 20; ++i)
    {
        for (int j{}; j < 20; ++j)
        {
            setColor(j % 15);
            x ++;
            goToPositionInConsole(x, y);
            std::cout << "#";
        }
        x = 0;
        y ++;
    }
    x = 10;
    y = 10;
    int lastX = x;
    int lastY = y;
    goToPositionInConsole(x, y);
    std::cout << 'P';
    while (true)
    {
        switch (_getch())
        {
        case 'w':
            --y;
            break;
        case 's':
            ++y;
            break;
        case 'a':
            --x;
            break;
        case 'd':
            ++x;
            break;
        default:
            break;
        }
        setColor((x*y) % 150);

        goToPositionInConsole(lastX, lastY);
        std::cout << "#";
        goToPositionInConsole(x, y);
        std::cout << 'P';

        lastX = x;
        lastY = y;
    }

    return 0;
}
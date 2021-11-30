#include "consoleattributes.h"
#include <windows.h> //To get access to console functionality. IE: SetConsoleCursorPosition

ConsoleAttributes::ConsoleAttributes()
{

}

void ConsoleAttributes::goToPositionInConsole(short x, short y)
{
    COORD coordinates;
    coordinates.X=x;
    coordinates.Y=y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

void ConsoleAttributes::consoleSize(int x, int y)
{
    HWND console{GetConsoleWindow()}; //HWND and GetConsoleWindow lies within the windows.h library
    RECT rect{};
    GetWindowRect(console, &rect); //Gets the current size of the console

    MoveWindow(console, rect.left, rect.top, x, y, true);
}

void ConsoleAttributes::toggleCursorVisibility(bool showCursor)
{
    HANDLE outputHandle=GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;

    cursorInfo.dwSize=1;
    GetConsoleCursorInfo(outputHandle, &cursorInfo);
    cursorInfo.bVisible=showCursor;
    SetConsoleCursorInfo(outputHandle, &cursorInfo);

}

void ConsoleAttributes::color(unsigned short color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

#ifndef CONSOLEATTRIBUTES_H
#define CONSOLEATTRIBUTES_H


class ConsoleAttributes
{
public:
    ConsoleAttributes();
    void goToPositionInConsole(short x, short y);
    void consoleSize(int x, int y);
    void toggleCursorVisibility(bool showCursor);
    void color(unsigned short color);

};

#endif // CONSOLEATTRIBUTES_H

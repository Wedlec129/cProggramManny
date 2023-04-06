#include <ncurses.h>
//gcc 4.c -lncurses
int main(){

    int x = 0, y = 0, ch = 0;
    if (NULL == initscr())  return __LINE__;
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    do {
        mvaddch(y, x,' ');

        switch(ch) {
            case K:
                y = (y + LINES - 1) % LINES;
                break;

            case KEY_DOWN:
                y = (y + 1) % LINES;
                break;

            case KEY_RIGHT:
                x = (x + 1) % COLS;
                break;

            case KEY_LEFT:
                x = (x + COLS - 1) % COLS;
                break;
            
        }

        mvaddch(y, x, '*');
        refresh();
    } while('q' != (ch = getch()));
    endwin();
    return 0;

 }

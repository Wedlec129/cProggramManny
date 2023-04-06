#include <ncurses.h>
#include <unistd.h>
//  gcc 5.c -lncurses&&./a.out



int main(){
    if (NULL == initscr())  return __LINE__;

    int x = COLS/2-1, y = LINES/2-1, ch = 0;
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    nodelay(stdscr,TRUE);

    enum direction{
        NONE,
        UP,
        DOWN,
        RIGHT,
        LEFT
    };

    enum direction dir=NONE;
    //ch = getch();
    //cbreak();
    
    int memoryLineSnakeX[25]={0};
    int memoryLineSnakeY[25]={0};
    int i=0, j=0;
    do {
        
        //mvaddch(y, x,' ');
        switch(ch) {
            case KEY_UP:
                dir=UP;
                break;

            case KEY_DOWN:
                dir=DOWN;
                y = (y + 1) % LINES;
                break;

            case KEY_RIGHT:
                dir=RIGHT;
                break;

            case KEY_LEFT:
                dir=LEFT;
                break;
            
        }

        //sleep(1);
        //printw("lol %d",a);
        
        //x = (x + 1) % COLS;

        if(dir==UP){
            y = (y + LINES - 1) % LINES;
        }
        if(dir==DOWN){
            y = (y + 1) % LINES;
        }
        if(dir==RIGHT){
           x = (x + 1) % COLS;
        }
        if(dir==LEFT){
           x = (x + COLS - 1) % COLS;
        }


       


        usleep(100000);
        
        memoryLineSnakeX[i]=x;
        memoryLineSnakeY[j]=y;

        mvaddch(y, x, '*');
        refresh();
        i++;j++;
        if(i>25-1){

            for(int q=0; q<25; q++){
                mvaddch(memoryLineSnakeY[q], memoryLineSnakeX[q],' ');
                }
            i=0;j=0;

        }


        


    } while('q' != (ch=getch()));
    

    return 0;

 }

#include<stdio.h>
#include<stdlib.h>
#include<ncurses.h>

#define MAX_X 30
#define MAX_Y 20

WINDOW *win, *frame;

int main(int argc,char *argv[]){
        int x = 0,y = 0;
        int c;
        char check;

        initscr();
        frame = newwin(MAX_Y+2,MAX_X+2,1,1);
        box(frame,'|','-');
        win = newwin(MAX_Y,MAX_X,2,2);
        noecho();
        wrefresh(frame);

        while(1){
            wmove(win,y,x);
            wrefresh(win);
            switch(c=getchar()){
                case 'h':
                    if(x>0){
                        x--;
                    }
                    break;
                case 'j':
                    if(y < MAX_Y-1){
                        y++;
                    }
                    break;
                case 'k':
                    if(y>0){
                        y--;
                    }
                    break;
                case 'l':
                    if(x<MAX_X-1){
                        x++;
                    }
                    break;
                case 'q':
                    endwin();
                    echo();
                    exit(0);
                    
                case '^':
                    x = 0;
                    while (mvwinch(win, y, x) == ' ' && x < MAX_X-1){
                        x++;
                    }
                    break;
                case '$':
                    x = MAX_X-1;
                    while (mvwinch(win, y, x) == ' ' && x > 0) {
                        x--;
                    }
                    x++;
                    break;
                case 'i':
                    while (1) {
                        char input=getchar();
                        if(input == 0x1B){
                            break;
                        }
                        waddch(win, input);
                        if(x<MAX_X-1){
                            x++;
                        }else{
                            x = 0;
                            y++;
                        }
                        wrefresh(win);
                    }
                    break;
                default :
                    break;    
                }
        }
}

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
        FILE *fp;
        char str[MAX_X+1];
        
        initscr();
        frame = newwin(MAX_Y+2,MAX_X+2,1,1);
        box(frame,'|','-');
        win = newwin(MAX_Y,MAX_X,2,2);
        noecho();
        wrefresh(frame);
        
        if (argc == 2) {
            fp = fopen(argv[1], "r");
            for (int i = 0; i < MAX_X*MAX_Y; i++) {
                c = getc(fp);
                if(c == EOF){
                    break;
                }
                waddch(win, c);
                if(x<MAX_X-1){
                    x++;
                }else{
                    x = 0;
                    y++;
                }
                
            }
            fclose(fp);
        } else if(argc >= 2){
            printf("引数が異常です\n");
            return -1;
        }

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
                case 'w':
                    fp = fopen("myeditor.txt", "w");
                    if (fp == NULL) {
                        return -1;
                    }

                	for(int i = 0; i < MAX_Y; i++) {
                		mvwinstr(win, i, 0, str);
                		fprintf(fp, "%s\n", str);
                	}

                	fclose(fp);
                    break;
                case 'i':
                    while (1) {
                        char input=getchar();
                        if(input == 0x1B){
                            break;
                        } else if(input == 0x0d){
                            x = 0;
                            y +=1;
                        } else {
                            winsch(win, input);
                            if(x<MAX_X-1){
                                x++;
                            }else{
                                x = 0;
                                y++;
                            }
                        }
                        wmove(win,y,x);
                        wrefresh(win);
                    }
                    break;
                default :
                    break;    
                }
        }
}

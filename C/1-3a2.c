#include <stdio.h>
int main(int argc, char *argv[]) {
    printf("argc:\t%d\n", argc);
    for(int i;i<argc;i++){
        printf("argv[%d]:\t%c\n", i, argv[i][0]);
    }
}
//レポートを書くときに、２次元配列になっているかチェックするためのファイル。適当にイジって遊べばOK

#include <stdio.h>
int main(int argc, char *argv[]) {
    printf("argc:\t%d\n", argc);
    for(int i;i<argc;i++){
        printf("argv[%d]:\t%s\n", i, argv[i]);
    }
}
//レポートを書くときに、２次元配列になっているかチェックするためのファイル。適当にイジって遊べばOK

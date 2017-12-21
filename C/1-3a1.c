#include <stdio.h>
int main(int argc, char *argv[]) {
    printf("argc:\t%d\n", argc);
    for(int i;i<argc;i++){
        printf("argv[%d]:\t%s\n", i, argv[i]);
    }
}

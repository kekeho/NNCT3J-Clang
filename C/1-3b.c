#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[]) {
    FILE *fp1, *fp2;
    int c;

    if(argv[1] == NULL){
        printf("ERROR: 引数が足りません\n");
        exit(1);
    }

    //option処理
    if(argv[1][0] == '-') {
        switch(argv[1][1]) {
            case 'i':
            if ((fp2 = fopen(argv[3], "r")) != NULL) {
                fclose(fp2);
                printf("ファイルを上書きしてもいいですか(y/n)");
                char yesorno;
                scanf("%c", &yesorno);
                if(yesorno != 'y') {
                    exit(1);
                } else {
                    fp2 = fopen(argv[3], "w");
                    if((fp1 = fopen(argv[2], "r")) == NULL) {
                        printf("そこにファイルなどなかった。\n");
                        exit(1);
                    }
                }
            }
            case 'f':
            fp2 = fopen(argv[3], "w");
            if((fp1 = fopen(argv[2], "r")) == NULL) {
                printf("そこにファイルなどなかった。\n");
                exit(1);
            }
        }
    } else {
        if((fp1 = fopen(argv[1], "r")) == NULL) {
            printf("そこにファイルなどなかった。\n");
            exit(1);
        }
        fp2 = fopen(argv[2], "w");
    }
    
    if(argv[1] == argv[2]) {
        printf("Error. 同じファイルを２つの引数で渡されてもそれはコピーと言えませんよ");
        exit(1);
    }
    
    
    while ( (c=fgetc(fp1)) != EOF) {
        fputc(c,fp2);
    }
    
    fclose(fp1);
    fclose(fp2);
    return 0;
}

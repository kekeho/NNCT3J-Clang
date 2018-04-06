# 課題1
## プログラムソース
```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    int a[20];
    int i;
    int sum = 0;
    srand(time(NULL));
    for(i=0; i<20; i++){
        a[i]=rand()%6+1;
        printf("%d\n", a[i]);
    }
    
    for(i=0;i<20;i++){
        sum += a[i];
    }
    printf("AVERAGE: %d\n", sum/20);
}
```

## プログラムの説明
1~6の範囲で乱数を20回発生させ、各回ごとにその結果を出力している。
さらに回数を重ねるごとにsum変数に値を加算し、最後に回数で割って平均値を出力している。

## 実行結果
```bash
2
4
1
3
2
1
5
5
2
5
3
2
5
5
2
5
1
1
6
3
AVERAGE: 3
```

## 実行結果の特徴
1〜6の間でほぼ均等に乱数が生成されている。数回実行してみた所平均は常に3であったため、ほぼ均等に乱数が生成されていることが裏付けられる。

## 考察
久々にC言語を書いたので、良い復習となったと思われる。


# 課題2
## プログラムソース
```c
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    int a[3];
    int i;
    int sum;
    srand(time(NULL));
    for(int n; n < 3; n++) {
        while(getchar() != '\n') ;
        a[n] = rand()%9+1;
        printf("%d\n", a[n]);
        if (n == 2 && a[0] == a[1] && a[1] == a[2]) {
            printf("ATARI!\n");
        } else if(n == 2) {
            printf("HAZURE\n");
        } 
    }
}
```

## プログラムの説明
Enterキーを押されるたびに乱数を生成する。
3回Enterキーが押されたら今までに生成された乱数がすべて等しいか評価し、全て等しい場合はATARI、そうでない場合はHAZUREを表示している。

## 実行結果
```bash

5

2

6
HAZURE
```

## 実行結果の特徴
ATARIが出ることはめったにない。

## 考察
このスロットゲームを楽しむためには、1つめが決まったところで2つめ、3つめが揃う確率を上げるなどの工夫が必要だと思った。

# 課題3a
## プログラムソース
```c
#include <stdio.h>
int main(int argc, char *argv[]) {
    printf("argc:\t%d\n", argc);
    for(int i;i<argc;i++){
        printf("argv[%d]:\t%s\n", i, argv[i]);
    }
}
```
以下は2次元配列になっているか確認するためのソース
```c
#include <stdio.h>
int main(int argc, char *argv[]) {
    printf("argc:\t%d\n", argc);
    for(int i;i<argc;i++){
        printf("argv[%d]:\t%c\n", i, argv[i][0]);
    }
}
```

## 実行結果
```bash
HirokiMBP:c hiroki$ ./a.out hoge fuga piyo
argc:   4
argv[0]:        ./a.out
argv[1]:        hoge
argv[2]:        fuga
argv[3]:        piyo
```
以下で、2次元配列になっているか確認している
```bash
HirokiMBP:c hiroki$ ./a.out hoge fuga piyo
argc:   4
argv[0]:        .
argv[1]:        h
argv[2]:        f
argv[3]:        p
```

## 実行結果の特徴
argcに引数の数が、argvに引数が格納されていることがわかる。

## 考察
argvに実行時のコマンドも含まれていることに注意してコードを書くべきだと思った。

# 課題3b
## プログラムソース
```c
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
```

## プログラムの説明
ファイルをコピーするプログラム。iオプション、fオプションを実装した。

## 実行結果
```bash
HirokiMBP:c hiroki$ ./a.out nya.txt wan.txt # 正常に実行された
HirokiMBP:c hiroki$ ./a.out
ERROR: 引数が足りません
HirokiMBP:c hiroki$ ./a.out -i nya.txt wan.txt #すでにwan.txtは存在する
ファイルを上書きしてもいいですか(y/n)y # 正常に実行された
```
## 実行結果の特徴
エラー処理がきちんと動いている。

## 考察
まだファイルのみしかコピーできないので、ディレクトリをコピーできるようにしたい。
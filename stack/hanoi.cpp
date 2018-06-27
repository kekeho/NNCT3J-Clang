#include <stdio.h>
#include <stdlib.h>
#define HEIGHT 5
#define TOWERS 3
#define True 1
#define False 0

#define scanf_s(fmt, ... ) scanf(fmt, __VA_ARGS__ ) //FOR NON-MS COMPILER/

struct _Stack {
        int stack[HEIGHT];
        int volume;
};
typedef struct _Stack Stack;


int init(Stack *stack) {
        //スタックの格納配列の初期化
        for (int i = 0; i < HEIGHT; i++) {
                stack->stack[i] = 0;
        }
        //現在位置を0に設定
        stack->volume = 0;
        return 0;
}


int push(Stack *stack, int num) {
        //Stack Overflow対策
        if (stack->volume >= HEIGHT) {
                return -1;
        }
        else {
                //引数で受け取った数を積み上げ
                stack->stack[stack->volume] = num;
                stack->volume++;
        }
        return 0;
}


int pop(Stack *stack) {
        //Stack Underflow対策
        if (stack->volume == 0) {
                return -1;
        }
        else {
                stack->volume--;
                int out = stack->stack[stack->volume];
                stack->stack[stack->volume] = 0;
                return out;
        }
}


void printStack(Stack *stack) {
        for (int i = 0; i < HEIGHT; i++) {
                printf("%d ", stack->stack[i]);
        }
        printf("\n");
}


int enableStack(Stack *from_tower, Stack *to_tower) {
        if (from_tower->volume == 0) {
                return false;
        }
        if ((from_tower->stack[from_tower->volume - 1] < to_tower->stack[to_tower->volume - 1]) || to_tower->volume == 0) {
                //移動元のタワーの最上位の値が、移動先の最上位の値より大きい もしくは移動先が
                return True;
        }
        else {
                return False;
        }
}


int checkFinish(Stack *tower, int blocks) {
        //blocksは段数
        //すべての値が0になっているかチェック
        for (int i = 0; i < blocks; i++) {
                if (tower->stack[i] != 0) {
                        return False;
                }
        }
        return True;
}


void printTower(Stack *towers, int blocks) {
        for (int i = 0; i < TOWERS; i++){
                printf("%d番目\t", i);
        }
        printf("\n========================\n");
        for (int i = blocks - 1; i >= 0; i--){
                for (int j = 0; j < TOWERS; j++) {
                        printf("%d\t", towers[j].stack[i]);
                }
                putchar('\n');
        }
}


int main() {
        int count = 1;
        int from_tower, to_tower;
        int tempNum;
        int blocks; //段数
        int flag;

        Stack towers[TOWERS];
        printf("段数を選んでください(3〜5): ");
        scanf_s("%d", &blocks);

        //初期化
        for (int i = 0; i < TOWERS; i++) {
                init(&towers[i]);
        }

        //第1塔に決められたブロックを積み重ね
        for (int i = blocks; i > 0; i--) {
                push(&towers[0], i);
        }

        printf("GAME START!\n");


        //ゲーム開始
        while (True){
                printf("[%d回目]\n", count);
                printTower(towers, blocks);
                printf("移動元と移動先を入力してください: ");
                scanf_s("%d %d", &from_tower, &to_tower);

                //存在しない塔への移動を弾く
                if (from_tower >= TOWERS || to_tower >= TOWERS) {
                        printf("存在しない塔が指定されました。リトライ\n");

                }
                //同じ塔から同じ塔に移動するのは無意味
                else if (from_tower == to_tower) {
                        printf("同じ塔の上で円盤が跳ねるだけで無意味。リトライ\n");
                } else {
                        if (enableStack(&towers[from_tower], &towers[to_tower]) == True) {
                                //移動可能なら移動
                                push(&towers[to_tower], pop(&towers[from_tower]));
                                count++;
                        } else {
                                printf("移動できません。やり直し\n");
                        }
                }
            
            //クリア判定
            if(checkFinish(&towers[0], blocks) && checkFinish(&towers[1], blocks)){
                printf("CLEAR!");
                break;
            }
            
            
        }
}
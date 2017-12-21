#include <stdio.h>
#include <stdlib.h>

#define HEIGHT 5
#define TOWERS 3

struct Stack {
	int stack[HEIGHT];
	int volume;
};

int init(struct Stack *stack) {
	//forループで初期化
	for (int i = 0; i < HEIGHT; i++)
	{
		stack->stack[i] = 0;
	}
	//現在位置を0番に指定
	stack->volume = 0;
	return 0;
}

int push(struct Stack *stack, int number) {
	if (stack->volume >= HEIGHT) { //スタックが満杯時のスタックオーバーフロー対策
		printf("ERROR: Stack overflow\n");
		exit(1);
	} else {
		//受け付けたnumberを位置に代入
		stack->stack[stack->volume] = number;
		//位置を一つ上にあげる
		stack->volume += 1;
	}
	return 0;
}

int pop(struct Stack *stack) {
	if (stack->volume == 0) { //スタックが空の時のスタックアンダーフロー対策
		printf("ERROR: Stack underflow\n");
		exit(1);
	} else {
		//位置を一つ下げる
		stack->volume -= 1;
		//returnする変数にスタックの一番上の値を代入してpopを実現
		int out = stack->stack[stack->volume];
		//popし終わったので0を代入して初期化
		stack->stack[stack->volume] = 0;
		//popした値を返す
		return out;
	}
}

void printTower(struct Stack *stack) {
	//forループで現在のスタック内の値を一覧表示
	for (int i = 0; i < HEIGHT; i++) {
		printf("%d ", stack->stack[i]);
	}
}

int enableStack(struct Stack *fromTower, struct Stack *toTower){
	if (toTower->volume == 0 && fromTower->volume != 0) {　//移動先の塔が空の場合
		return 1;
	} else if (toTower->stack[fromTower->volume - 1] > fromTower->stack[toTower->volume - 1] && fromTower->volume != 0) {　//移動元の塔の最上位の値が移動先の塔の最上位の値より大きい場合
		return 1;
	} else { //その他の場合は移動が不可能
		return 0;
	}
}

//クリア判定
int checkFinish(struct Stack *tower, int blocks){
	int cnt = blocks;
	for (int i = 0; i < cnt; i++) {
		if(tower->stack[i] != blocks)
			return 0;
		blocks--;
	}
	return 1;
}

int main() {
	int i;
	int count=1;
	int fromTower, toTower;
	int tempNumber;
	int blocks;
	struct Stack tower[TOWERS];
	
	//3塔の初期化
	for (i = 0; i < TOWERS; i++) {
		init(&tower[i]);
	}
	
	printf("段数を選んで下さい: 3,4,5\n");
	scanf("%d", &blocks);
	//段数が3~5かチェック
	if (blocks < 3) {
		puts("少なすぎます");
		exit(1);
	} else if (blocks > 5) {
		puts("多すぎます");
		exit(1);
	}
	
	//初期設定。1つめの塔にすべてのブロックを積む。
	for (i = blocks; i > 0; i--) {
		push(&tower[0], i);
	}
	
	//塔の状態を表示する
	for (i = 0; i < blocks; i++) {
		printf("%d:", i + 1);
		printTower(&tower[i]);
	}
	putchar('\n');
	
	//ここからがゲーム本体
	while (true) {
		printf("%d回目の移動です.\n", count);
		printf("どの搭からどの搭へ移動させますか?[?>?]:"); scanf("%d>%d", &fromTower, &toTower);
		
		//移動させる
		if (enableStack(&tower[fromTower - 1], &tower[toTower - 1]) == 1){
			push(&tower[toTower - 1], pop(&tower[fromTower - 1]));
		} else {
			printf("ルール: 移動できません。\n");
		}
		
		//塔の状態表示
		for (i = 0; i < blocks; i++) {
			printf("%d:", i + 1);
			printTower(&tower[i]);
		}
		putchar('\n');
		
		//終わったかどうか
		if ((checkFinish(&tower[1], blocks) == 1) || (checkFinish(&tower[2], blocks) == 1)) {
			printf("CLEAR!!\n");
			break;
		}
		count++;
	}
	return 0;
}

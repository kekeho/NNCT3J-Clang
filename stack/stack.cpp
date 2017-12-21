#include <stdio.h>
#include <stdlib.h>

#define HEIGHT 5
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

void printTower(struct Stack stack) {
	//forループで現在のスタック内の値を一覧表示
	for (int i = 0; i < HEIGHT; i++) {
		printf("%d ", stack.stack[i]);
	}
	printf("\n");
}

int main() {
	struct Stack stack;

	init(&stack);
	push(&stack, 10);
	push(&stack, 20);
	printTower(stack);
	printf("%d\n", pop(&stack));
	printf("%d\n", pop(&stack));
	printTower(stack);
	pop(&stack);
	return 0;
}

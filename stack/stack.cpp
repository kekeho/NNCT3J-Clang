#include <stdio.h>
#define HEIGHT 5


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
	for (int i = 0; i < HEIGHT; i++){
		printf("%d ", stack->stack[i]);
	}
	printf("\n");
}


int main() {
	Stack stack;
	init(&stack);

	push(&stack, 10);
	push(&stack, 20);
	push(&stack, 30);
	printf("%d\n", pop(&stack));
	printf("%d\n", pop(&stack));
	printf("%d\n", pop(&stack));
	push(&stack, 40);

	printStack(&stack);
}
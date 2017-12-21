#include <stdio.h>
#define QUEUE_SIZE 4

int queue[QUEUE_SIZE];
int quantity = 0;

int initQueue() {
	for (int i = 0; i < QUEUE_SIZE; i++){
		queue[i] = 0;
	}
	return 0;
}

int enqueue(int data) {
	//エラー処理
	if (quantity >= QUEUE_SIZE){ //残領域の無い時
		return -101; 
	}
	if (data <= 0) { //負の値が入力された際
		return -102;
	}

	//配列のキューにデータを保存する
	queue[quantity] = data;
	quantity++;
	return 0;
}


int dequeue() {
	if (queue[0] == 0) {
		return -201;
	}
	int dequeueValue = queue[0];
	
	//再構築
	for (int i = 0; i < quantity; i++){
		queue[i] = queue[i + 1];
	}
	quantity--;
	queue[quantity] = 0;


	return dequeueValue;
}

//キュー配列の中身を一覧表示
int showQueue() {
	putchar('|');
	for (int i = 0; i < QUEUE_SIZE; i++){
		printf("%d | ", queue[i]);
	}
	putchar('\n');
	return 0;
}

//エラーメッセージ表示関数
int showResult(int result) {
	switch (result) {
	case -101:
		printf("ERROR %d: 残領域がありません\n", result);
		break;
	case -102:
		printf("ERROR %d: 負のデータが入力されています\n", result);
		break;
	case -201:
		printf("ERROR %d: 取り出せるデータがありません\n", result);
		break;
	case 0:
		printf("格納成功\n");
		break;
	default:
		printf("取り出し成功: %d\n", result);
		break;
	}

	return 0;
}


int main() {
	initQueue();
	showResult(enqueue(10));
	showResult(enqueue(20));
	showResult(enqueue(30));
	showResult(enqueue(-30));
	showQueue();
	showResult(dequeue());
	showResult(dequeue());
	showResult(dequeue());
	showResult(dequeue());
	showQueue();
	return 0;
}

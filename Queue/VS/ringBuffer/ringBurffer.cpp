#include <stdio.h>
#define QUEUE_SIZE 5

struct queue {
	int array[QUEUE_SIZE]; //データが入る配列
	int wp; //次にデータを入れる場所の配列番号
	int quantity; //データの個数
};

int initQueue(struct queue *obj) {
	obj->quantity = 0;
	obj->wp = 0;
	for (int i = 0; i < QUEUE_SIZE; i++) {
		obj->array[i] = 0;
	}
	return 0;
}

int enqueue(struct queue *obj, int data) {
	if (obj->quantity >= QUEUE_SIZE) { //残領域の無い時
		return -101;
	}
	if (data <= 0) { //負の値が入力された際
		return -102;
	}
	obj->array[obj->wp] = data;

	//wpをplusする処理
	if (obj->wp == QUEUE_SIZE - 1) { //リングが一周
		obj->wp = 0;
	}
	else {
		obj->wp++;
	}

	obj->quantity++;

	return 0;
}

int dequeue(struct queue *obj) {
	//dequeueする位置(dequeuePoint)の計算
	int dequeuePoint;
	if (obj->wp - obj->quantity < 0) {
		dequeuePoint = QUEUE_SIZE + (obj->wp - obj->quantity);
	}
	else {
		dequeuePoint = obj->wp - obj->quantity;
	}
	if (obj->array[dequeuePoint] == 0) {
		return -201;
	}
	int dequeueValue = obj->array[dequeuePoint];
	obj->array[dequeuePoint] = 0;
	obj->quantity--;

	return 0;
}

int showQueue(struct queue *obj) {
	putchar('|');
	for (int i = obj->wp - obj->quantity; i < QUEUE_SIZE; i++) {
		if (i < 0) {
			printf("%d | ", obj->array[QUEUE_SIZE + (obj->wp - obj->quantity)]);
		}
		else {
			printf("%d | ", obj->array[i]);
		}

	}
	putchar('\n');
	return 0;
}

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
	case 200:
		printf("ERROR %d: 予期しえないエラーが発生しました\n", result);
		break;
	default:
		printf("取り出し成功: %d\n", result);
		break;
	}

	return 0;
}

int main() {
	struct queue Queue;
	initQueue(&Queue);
	enqueue(&Queue, 10);
	showQueue(&Queue);
	enqueue(&Queue, 20);
	showQueue(&Queue);
	enqueue(&Queue, 30);
	showQueue(&Queue);
	dequeue(&Queue);
	dequeue(&Queue);
	enqueue(&Queue, 40);
	enqueue(&Queue, 50);
	enqueue(&Queue, 60);
	dequeue(&Queue);
	dequeue(&Queue);
	enqueue(&Queue, 70);
	showQueue(&Queue);
	return 0;
}
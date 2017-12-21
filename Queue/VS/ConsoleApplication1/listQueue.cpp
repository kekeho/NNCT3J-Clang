#include <stdio.h>
#include <stdlib.h>

struct queue{
	int val;
	struct queue *addr;
};

struct queue *bottomQueue = NULL;
struct queue *topQueue = NULL;

int enqueue(int data) {
	int returnVal = 1; //返り値の宣言
	struct queue *newQueue;
	//メモリを動的確保
	newQueue = (struct queue*)malloc(sizeof(struct queue));

	if (newQueue == NULL){ //メモリ確保失敗時
		returnVal = 0;
	}else {
		newQueue->val = data; //データを追加
		newQueue->addr = NULL; //新しいqueueのアドレス値

		if (bottomQueue == NULL) { //まだ1つもqueueのないとき
			bottomQueue = newQueue; //最古のqueueを更新
			topQueue = newQueue; //最新のqueueを更新
		}
		else {
			topQueue->addr = newQueue; //連結
			topQueue = newQueue; //最新のqueueの更新
		}
	}

	

	return returnVal;
}

int dequeue() {
	int returnVal = 0; //返り値
	struct queue *new_bottom;

	if (topQueue == bottomQueue && bottomQueue != NULL){
		returnVal = bottomQueue->val;
		free(bottomQueue);
		free(topQueue);
		topQueue = NULL;
		bottomQueue = NULL;
	} else if (topQueue != NULL && bottomQueue != NULL) {
		returnVal = bottomQueue->val;
		struct queue *log = bottomQueue->addr;
		free(bottomQueue);
		bottomQueue = log; //更新
	}else if (bottomQueue == NULL) {
			returnVal = -201;
		}
	else {
		returnVal = -200;
	}

	return returnVal;
}

int showResult(int result) {
	switch (result) {
	case 1:
		printf("格納成功\n");
		break;
	case 0:
		printf("ERROR %d: メモリの確保ができませんでした\n", result);
		break;
	case -201:
		printf("ERROR %d: 取り出せるデータがありません\n", result);
		break;
	default:
		printf("取り出し成功\n");
		break;
	}

	return 0;
}

int showQueue() {
	struct queue *x;
	x = bottomQueue;
	while (1) {
		printf("%d | ", x->val);
		x = x->addr;

		if (x == topQueue) {
			printf("%d\n", x->val);
			break;
		}
	}
	return 0;
}



void main() {
	int result = enqueue(10); showResult(result);
	enqueue(20);
	enqueue(30);
	result = dequeue(); showResult(result);
	showQueue();

}
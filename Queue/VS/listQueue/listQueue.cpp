#include <stdio.h>
#include <stdlib.h>

struct queue {
	int val;
	struct queue *addr;
};

struct queue *bottomQueue = NULL;
struct queue *topQueue = NULL;

int enqueue(int data) {
	int returnVal = 1; //�Ԃ��l�̐錾
	struct queue *newQueue;
	//�������𓮓I�m��
	newQueue = (struct queue*)malloc(sizeof(struct queue));

	if (newQueue == NULL) { //�������m�ێ��s��
		returnVal = 0;
	}
	else {
		newQueue->val = data; //�f�[�^���ǉ�
		newQueue->addr = NULL; //�V����queue�̃A�h���X�l

		if (bottomQueue == NULL) { //�܂�1��queue�̂Ȃ��Ƃ�
			bottomQueue = newQueue; //�ŌÂ�queue���X�V
			topQueue = newQueue; //�ŐV��queue���X�V
		}
		else {
			topQueue->addr = newQueue; //�A��
			topQueue = newQueue; //�ŐV��queue�̍X�V
		}
	}



	return returnVal;
}

int dequeue() {
	int returnVal = 0; //�Ԃ��l
	struct queue *new_bottom;

	if (topQueue == bottomQueue && bottomQueue != NULL) {
		returnVal = bottomQueue->val;
		free(bottomQueue);
		free(topQueue);
		topQueue = NULL;
		bottomQueue = NULL;
	}
	else if (topQueue != NULL && bottomQueue != NULL) {
		returnVal = bottomQueue->val;
		struct queue *log = bottomQueue->addr;
		free(bottomQueue);
		bottomQueue = log; //�X�V
	}
	else if (bottomQueue == NULL) {
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
		printf("�i�[����\n");
		break;
	case 0:
		printf("ERROR %d: �������̊m�ۂ��ł��܂����ł���\n", result);
		break;
	case -201:
		printf("ERROR %d: �����o�����f�[�^�������܂���\n", result);
		break;
	default:
		printf("�����o������: %d\n", result);
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



int main() {
	int result = enqueue(10); showResult(result);
	enqueue(20);
	enqueue(30);
	result = dequeue(); showResult(result);
	showQueue();

}

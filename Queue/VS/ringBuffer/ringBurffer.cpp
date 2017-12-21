#include <stdio.h>
#define QUEUE_SIZE 5

struct queue{
	int array[QUEUE_SIZE]; //�f�[�^�������z��
	int wp; //���Ƀf�[�^���������ꏊ�̔z���ԍ�
	int quantity; //�f�[�^�̌�
};

int initQueue(struct queue *obj) {
	obj->quantity = 0;
	obj->wp = 0;
	for (int i = 0; i < QUEUE_SIZE; i++){
		obj->array[i] = 0;
	}
	return 0;
}

int enqueue(struct queue *obj, int data) {
	if (obj->quantity >= QUEUE_SIZE) { //�c�̈��̖�����
		return -101;
	}
	if (data <= 0) { //���̒l�����͂��ꂽ��
		return -102;
	}
	obj->array[obj->wp] = data;

	//wp��plus���鏈��
	if (obj->wp == QUEUE_SIZE-1){ //�����O������
		obj->wp = 0;
	}else {
		obj->wp++;
	}

	obj->quantity++;

	return 0;
}

int dequeue(struct queue *obj) {
	//dequeue�����ʒu(dequeuePoint)�̌v�Z
	int dequeuePoint;
	if (obj->wp - obj->quantity < 0) {
		dequeuePoint = QUEUE_SIZE + (obj->wp - obj->quantity);
	}else {
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
		printf("ERROR %d: �c�̈悪�����܂���\n", result);
		break;
	case -102:
		printf("ERROR %d: ���̃f�[�^�����͂����Ă��܂�\n", result);
		break;
	case -201:
		printf("ERROR %d: �����o�����f�[�^�������܂���\n", result);
		break;
	case 200:
		printf("ERROR %d: �\�������Ȃ��G���[���������܂���\n", result);
		break;
	default:
		printf("�����o������: %d\n", result);
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

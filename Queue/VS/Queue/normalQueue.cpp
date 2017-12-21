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
	//�G���[����
	if (quantity >= QUEUE_SIZE){ //�c�̈�̖�����
		return -101; 
	}
	if (data <= 0) { //���̒l�����͂��ꂽ��
		return -102;
	}

	//�z��̃L���[�Ƀf�[�^��ۑ�����
	queue[quantity] = data;
	quantity++;
	return 0;
}


int dequeue() {
	if (queue[0] == 0) {
		return -201;
	}
	int dequeueValue = queue[0];
	
	//�č\�z
	for (int i = 0; i < quantity; i++){
		queue[i] = queue[i + 1];
	}
	quantity--;
	queue[quantity] = 0;


	return dequeueValue;
}

//�L���[�z��̒��g���ꗗ�\��
int showQueue() {
	putchar('|');
	for (int i = 0; i < QUEUE_SIZE; i++){
		printf("%d | ", queue[i]);
	}
	putchar('\n');
	return 0;
}

//�G���[���b�Z�[�W�\���֐�
int showResult(int result) {
	switch (result) {
	case -101:
		printf("ERROR %d: �c�̈悪����܂���\n", result);
		break;
	case -102:
		printf("ERROR %d: ���̃f�[�^�����͂���Ă��܂�\n", result);
		break;
	case -201:
		printf("ERROR %d: ���o����f�[�^������܂���\n", result);
		break;
	case 0:
		printf("�i�[����\n");
		break;
	default:
		printf("���o������: %d\n", result);
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

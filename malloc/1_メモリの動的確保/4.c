#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printResult(int* array, int length){
    int i;

    printf("[ ");
    for(i = 0; i <  length; i++){
        printf("%d ", array[i]);
    }
    printf(" ]\n");   
};

// ピボットを取得する関数
int GetPivot(int array[], int start, int end){
	int center = (end - start) / 2 + start;

	if (array[start] >= array[center] && array[end] >= array[center]){
			if(array[start] >= array[end])
			{
				return array[end];
			}
			else
			{
				return array[start];
			}
		}
		else if (array[start] <= array[center] && array[end] <= array[center]){
			if (array[start] <= array[end])
			{
				return array[end];
			}
			else
			{
				return array[start];
			}
		}

		return array[center];
}

// 二つの値を交換する関数
void Swap(int* num1, int* num2){
	if (*num1 != *num2){
		*num1 ^= *num2;
		*num2 ^= *num1;
		*num1 ^= *num2;
	}
}

// 昇順にクイックソートをする関数
void QuickSort(int array[], int start, int end){
	if (start != end && start < end){
		int pivot;

		pivot = GetPivot(array, start, end);

		int left = start;
		int right = end;

		while (1){
			while (left <= end){
				if (array[left] >= pivot){
					break;					
				}
				left++;
			}

			while (right >= start){
				if (array[right] < pivot){
					break;
				}
				right--;
			}

			if (left == right + 1){
				if (right < start){
					right = start;
					left = start + 1;

					if (array[start] > array[end]){
						Swap(&array[start], &array[end]);
					}
				}
				break;
			}
			else{
				Swap(&array[left], &array[right]);
			}
		}

		// ******* 再帰的にクイックソートをかける ******* //
		QuickSort(array, start, right );
		QuickSort(array, left, end);		
	}
}

int main(){
    srand((unsigned)time(NULL));
    
    int* array;
    int length;
    int num = 0;
    int i;
    
    printf("nの値: ");
    scanf("%d", &num);
    length = num;
  
    array = malloc(sizeof(int) * num);

    if(array == NULL){
        printf("Error : Out of memory");
        exit(1);
    }
        
    for(i = 0; i < num; i++ ){
        array[i] = rand();
    }
    
    QuickSort(array, 0, num - 1);
    
    printf("ソート結果\n");
    printResult(array, num);

    while(1){
        printf("続けますか? 1/0 : ");
        scanf("%d", &i);

        if(i == 0){
            break;
        }

        printf("nの値: ");
        scanf("%d", &num);

        array = realloc(array, sizeof(int) * num);
        
        if(array == NULL){
            printf("Error: Out of memory");
            exit(1);
        }
        
        for(i = length; i < num; i++ ){
            array[i] = rand() % 100;
        }

        length = num;
    
        QuickSort(array, 0, num - 1);
    
        printf("ソート結果\n");
        printResult(array, num);
    }
    
    free(array);
       
    return 0;
}

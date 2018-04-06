#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    int a[20];
    int i;
    int sum = 0;
    srand(time(NULL));
    for(i=0; i<20; i++){
        a[i]=rand()%6+1;
        printf("%d\n", a[i]);
    }
    
    for(i=0;i<20;i++){
        sum += a[i];
    }
    printf("AVERAGE: %d\n", sum/20);
}

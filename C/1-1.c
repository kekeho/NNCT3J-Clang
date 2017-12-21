#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    int a[20];
    int i;
    int sum;
    srand(time(NULL));
    for(i=0; i<20; i++){
        a[i]=rand()%6+1;
    }
    
    for(i=0;i<20;i++){
        sum += a[i];
    }
    printf("%d\n", sum/20);
}

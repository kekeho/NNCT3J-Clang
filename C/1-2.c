#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    int a[3];
    srand(time(NULL));

    for(int n; n < 3; n++) {
        // while(getchar() != '\n');
        a[n] = rand()%9+1;
        printf("%d\n", a[n]);
        if (n == 2 && a[0] == a[1] && a[1] == a[2]) {
            printf("ATARI!\n");
        } else if(n == 2) {
            printf("HAZURE\n");
        } 
    }
}

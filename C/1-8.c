#include <stdio.h>
#define True 1
#define False 0
#define MAX 4

typedef struct{
    int hour;
    int minute;
    int second;
} TIME;

TIME sumcal(TIME *);

int main(){
    TIME lap[MAX] = {0, 0, 0};
    int hour_buffer;
    int min_buffer;
    int sec_buffer;

    for(int i = 0; i < MAX; i++){
        printf("INPUT TIME (hour minute second): ");
        scanf("%d %d %d", &hour_buffer, &min_buffer, &sec_buffer);

        //time formatting
        if(sec_buffer >= 60){
            min_buffer += sec_buffer / 60;
            sec_buffer = sec_buffer % 60;
        }
        if(min_buffer >= 60){
            hour_buffer += min_buffer / 60;
            min_buffer = min_buffer % 60;
        }

        lap[i].hour = hour_buffer;
        lap[i].minute = min_buffer;
        lap[i].second = sec_buffer;
    }

    TIME sum = sumcal(lap);
    printf("H:\t%d\nM:\t%d\nS:\t%d\n", sum.hour, sum.minute, sum.second);

}

TIME sumcal(TIME lap[]){
    TIME sum = {0, 0, 0};

    for(int i = 0; i < MAX; i++){
        sum.hour += lap[i].hour;
        sum.minute += lap[i].minute;
        sum.second += lap[i].second;
    }
    
    //time formatting
    if(sum.second >= 60){
        sum.minute += sum.second / 60;
        sum.second = sum.second % 60;
    }
    if(sum.minute >= 60){
        sum.hour += sum.minute / 60;
        sum.minute = sum.minute % 60;
    }
    return sum;
}
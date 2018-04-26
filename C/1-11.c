#include <stdio.h>
#include <math.h>

#define PI 3.141592

typedef struct{
    double x;
    double y;
} Point;

FILE *file;

int main(){
    //正四角形を作成する
    //for R-lang
    Point rect[10];

    for(int i = 0; i < 10; i++){
        if(i%2 == 0){
            rect[i].x = cos(M_PI * (1.0 / 5.0) * i) * 0.5;
            rect[i].y = sin(M_PI * (1.0 / 5.0) * i) * 0.5;
        } else {
            rect[i].x = cos(M_PI * (1.0 / 5.0) * i);
            rect[i].y = sin(M_PI * (1.0 / 5.0) * i);
        }
    }
    file = fopen("star.dat", "w");
    fprintf(file, " X Y\n");
    for(int i = 0; i < 10; i++){
        fprintf(file, "%d %lf %lf\n", i+1, rect[i].x, rect[i].y);
    }
    fclose(file);
}
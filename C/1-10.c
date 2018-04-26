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
    Point rect[4];

    for(int i = 1; i < 8; i+=2){
        rect[(i-1)/2].x = cos(M_PI * (1.0 / 4.0) * i);
        rect[(i-1)/2].y = sin(M_PI * (1.0 / 4.0) * i);
    }
    file = fopen("rect.dat", "w");
    fprintf(file, " X Y\n");
    for(int i = 0; i < 4; i++){
        fprintf(file, "%d %lf %lf\n", i+1, rect[i].x, rect[i].y);
    }
    fclose(file);
}
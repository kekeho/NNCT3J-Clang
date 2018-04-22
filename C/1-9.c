#include <stdio.h>
#include <math.h>

#define PI 3.141592

typedef struct{
    double x;
    double y;
} Point;

FILE *file;

int main(){
    //正三角形を作成する
    //for R-lang
    int len = 10;
    Point triangle[3];

    for(int i = 0; i < 3; i++){
        triangle[i].x = cos(M_PI * (2.0 / 3.0) * i);
        triangle[i].y = sin(M_PI * (2.0 / 3.0) * i);
    }
    file = fopen("triangle.dat", "w");
    fprintf(file, " X Y\n");
    for(int i = 0; i < 3; i++){
        fprintf(file, "%d %lf %lf\n", i+1, triangle[i].x, triangle[i].y);
    }
    fclose(file);
}
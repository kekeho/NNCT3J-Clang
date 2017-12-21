#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct point{
    double x,y;
}Point;

Point* talloc(int num){
    Point* p = (Point*)malloc(sizeof(Point) * num);

    if(p == NULL){
        printf("Error : Out of memory\n");
        exit(1);
    }
    
    return p;
}

void calcXY(double radius, Point* point, int n){
    int i;

    double deltaTheta = (2 * M_PI) / n; // デルタの差分
    double theta = 0;
    
    for(i = 0; i  < n ; i++)
    {
        point[i].x = radius * cos(theta);
        point[i].y = radius * sin(theta);
        theta += deltaTheta;
    }
}


int main(int argc, char* argv[]){
    if(argc < 3){
        printf("Error");
        return 1;
      }
  
    double radius = atof(argv[1]);
    printf("%s\n", argv[1]);
    int n = atoi(argv[2]);
    
    Point* point = talloc(n);
    
    calcXY(radius, point,  n);

    int i;
    for(i = 0; i < n ; i++){
        printf("%f %f\n", point[i].x, point[i].y );
    }
    printf("%f %f\n", point[0].x, point[0].y );
    
    return 0;
}  
    

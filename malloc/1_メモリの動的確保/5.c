#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
	double x,y;
}Point;

double calcRad(int dig){
	return dig * M_PI / 180;
}



void calcXY(double radius, Point point[]){
	int i;
	double theta = 0;
	double dTheta = calcRad(120);
	
	for(i = 0; i < 4; i++){
		point[i].x = radius * cos(theta);
		point[i].y = radius * sin(theta);
		theta += dTheta;
	}
}

int main(){
    Point point[4];

    calcXY(5, point);

    int i;

    for(i = 0; i < 4; i++){
        printf("%f %f\n", point[i].x, point[i].y );
    }
    
    return 0;
} 

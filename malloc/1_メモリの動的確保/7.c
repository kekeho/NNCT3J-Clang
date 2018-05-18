#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct point{
    double x;
    double y;
}Point;

Point* talloc(int num){
  Point* p = (Point*)malloc(sizeof(Point) * num);

  if(p == NULL){
      printf("Error : Out of memory\n");
      exit(1);
    }
  
  return p;
}

double radians(int deg){
  return deg * M_PI / 180;
}

void calcXY(double radius, Point* point, int n){
  int i;

  double deltaTheta = (2 * M_PI) / n; // デルタの差分
  double theta = 0;
    
  for(i = 0; i  < n; i++){
      point[i].x = radius * cos(theta) + 90;
      point[i].y = radius * sin(theta) + 90;
      theta += deltaTheta;
    }
}

// 指定した分だけ回転する
void Rotate( double theta, Point* point, int n){
  int i;
  double x;
  double y;
    
  for(i = 0; i < n; i++){
      x = point[i].x;
      y = point[i].y;
                
      point[i].x = x * cos(theta) - y * sin(theta);
      point[i].y = x * sin(theta) + y * cos(theta);
    }  
}

int main(int argc, char* argv[]){
  if(argc < 3){
      printf("Error");
      return 1;
    }
  
  //argv[1] = n角形
  int n = atof(argv[1]);
  double radius = 360 / n;
  //argv[2] = 回転させる角度
  int deg = atoi(argv[2]);
    
  Point* point = talloc(n);
    
  calcXY(radius, point, n);
  int i;
  for(i = 0; i < n ; i++){
      printf("%f %f\n", point[i].x, point[i].y );
    }
  printf("%f %f\n", point[0].x, point[0].y );

  //回転
  Rotate(radians(deg), point, n);
  for(i = 0; i < n ; i++){
      printf("%f %f\n", point[i].x, point[i].y );
    }
  printf("%f %f\n", point[0].x, point[0].y);

    
  return 0;
}  
    

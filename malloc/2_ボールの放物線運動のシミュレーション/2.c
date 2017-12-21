#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct _vector{
    double x;
    double y;
    double z;
}Vector;

double radians(int degree){
  return degree * M_PI / 180;
}

int main(int argc, char* argv[]){
  if(argc < 7){
    printf("Error");
    return 1;
  }
  
  int step = atoi(argv[1]);
  double velocity = atof(argv[2]);
  double theta1 = atof(argv[3]); // 仰俯角
  double theta2 = atof(argv[4]); // x軸に対する角度
  double dt = atof(argv[5]);
  double e = atof(argv[6]);
  
  float g = 9.8;       

  Vector vector; // 速度用
  Vector*  point;// 座標
  point = (Vector*)malloc(sizeof(Vector)* step);

  if(point == 0){
      printf("Error");
      return 0;
    }

  // 角座標軸方向の速度を出す
  vector.x = velocity * cos(theta1 * M_PI / 180);
  vector.y = vector.x;
  vector.x *= cos(radians(theta2));
  vector.y *= sin(radians(theta2));
  vector.z = velocity * sin(radians(theta1));
    
  int i;
  int j = 0;
    
  double t;
  double tz; // Z軸方向の時間
  
  for(i = 0; i < step; i++){
      t = dt * i;
      tz = dt * j;
        
      if(vector.z <= 0){
          vector.z = (-vector.z) * e;
          j = -1;        
        }
        
      point[i].x = vector.x * t;
      point[i].y = vector.y * t;
      point[i].z = vector.z * tz  - (g * tz * tz)/ 2;

      if(point[i].z < 0){
          vector.z = (-vector.z) * e;
          j = -1;
        }
       
      j++;
    }

  for(i = 0; i < step; i++){
      printf("%lf %lf %lf\n", point[i].x, point[i].y, point[i].z);
    }
    
  free(point);
    
  return 0;
}

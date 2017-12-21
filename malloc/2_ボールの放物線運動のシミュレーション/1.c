#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct _vector{
    float x;
    float y;
    float z;
}Vector;

double radians(int degree){
  return degree * M_PI / 180;
}

int main(int argc, char* argv[]){
  if(argc < 6){
    printf("Error!");
    return 1;
  }
  
  int step = atoi(argv[1]);
  double velocity = atof(argv[2]);
  double theta1 = atof(argv[3]); // 仰俯角
  double theta2 = atof(argv[4]); // x軸に対する角度
  double dt = atof(argv[5]);
  
  float g = 9.8;       

  Vector vector; // 速度用
  Vector*  point;// 座標
  point = (Vector*)malloc(sizeof(Vector)* step);

  if(point == 0){
      printf("Error");
      return 0;
    }

    // 角座標軸方向の速度を出す
    vector.x = velocity * cos(radians(theta1));
    vector.y = velocity * cos(radians(theta1));
    vector.x *= cos(radians(theta2));
    vector.y *= sin(radians(theta2));
    vector.z = velocity * sin(radians(theta1));
    
    int i;
    double t;
    int dvz;
    int vz = 0;
    int dz;
    for(i = 0; i < step; i++){
        t = dt * i;
        
        point[i].x = vector.x * t;
        point[i].y = vector.y * t;
        dvz = -1*g*t;
        vz+=dvz;
        dz=vz+dt;
        
        point[i].z = dz;        
    }

    for(i = 0; i < step; i++){
        printf("%f %f %f\n", point[i].x, point[i].y, point[i].z);
    }
    
    free(point);
    
    return 0;
}

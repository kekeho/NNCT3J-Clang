#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct _vector{
    double x;
    double y;
    double z;
}Vector;

typedef struct _physicsParam{
    int step;
    double theta1; // gyoukaku
    double theta2;
    double velocity;
    double dt;
    double e;
    double g;
}PhysicsParam;

void CalcPoint(Vector* point, PhysicsParam param){
    int i, j = 0;
    double t, tz;
    
    Vector vector;
    vector.x = param.velocity * cos(param.theta1 * M_PI / 180);
    vector.y = vector.x;
    vector.x *= cos(param.theta2 * M_PI / 180);
    vector.y *= sin(param.theta2 * M_PI / 180);
    vector.z = param.velocity * sin(param.theta1 * M_PI / 180);

    double velocity = vector.z;
    
    for(i = 0; i < param.step; i++){
        t = param.dt * i;
        tz = param.dt * j;

        velocity -= param.g * param.dt;
        
        point[i].x = vector.x * t;
        point[i].y = vector.y * t;
        point[i].z = vector.z * tz  - (param.g * tz * tz)/ 2;

        if(point[i].z < 0){
            vector.z = (-velocity) * param.e;
            velocity = -velocity;
            
            j = 0;
        }
        else{
            j++;
        }
        
    }
       
}

int main(int argc, char* argv[]){
    if(argc != 7){
        printf("error\n");
        return -1;
    }

    PhysicsParam param;
   
    param.step = atoi(argv[1]);
    param.theta1 = atof(argv[2]);
    param.theta2 = atof(argv[3]);
    param.velocity = atof(argv[4]);
    param.dt = atof(argv[5]);
    param.e = atof(argv[6]);
    
    param.g = 9.8;

    Vector* point = (Vector*)malloc(sizeof(Vector)*param.step);

    if(point == 0){
        printf("error\n");
        return -1;
    }

    CalcPoint(point, param);

    int i;
    FILE* gp;

    gp = popen("gnuplot -persist", "w");
    fprintf(gp, "set xrange [0.0:3000.0]\n");
    fprintf(gp, "set yrange [0.0:3000.0]\n");
    fprintf(gp,"set zrange [0:800]\n");
    fprintf(gp,"set ticslevel 0\n");  //z軸を０に調整のため書いておく。
    fprintf(gp, "splot '-' with lines title "kadai2-3"\n");

    fflush(gp);
    for(i = 0; i < param.step; i++){
        fprintf(gp, "%lf %lf %lf\n", point[i].x, point[i].y, point[i].z);
    }
    fprintf(gp, "e\n");
    fflush(gp);
    
    pclose(gp);

    free(point);

    return 0;
}

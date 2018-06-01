#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Vector{
    double t, x, y, z;
} Vector;


int main(int argc, char const *argv[]){
    //Init
    double dx, dy, dz; //変化量
    double vx, vy, vz; //速度
    double dvz;
    double v = 10; //速度
    double dt = 0.05;
    double g = -9.8;
    double x, y, z, t = 0;
    double theta, theta2 = 1.0/sqrt(2.0);
    FILE *fp; //File pointer
    FILE *pipe;//UNIX pipe
    pipe = popen("gnuplot -persist", "w");
    fprintf(pipe, "set terminal postscript eps color\n");

    //Input Loop time and malloc
    int loop;
    printf("Input loop: ");
    scanf("%d", &loop);
    Vector *array;
    array = (Vector*)malloc(sizeof(Vector)*loop);

    //calc
    vx = v * cos(theta) * cos(theta2);
    vy = v * cos(theta) * sin(theta2);
    vz = v * sin(theta);

    dx = vx * dt;
    dy = vy * dt;

    fprintf(pipe, "splot '-' w p lt 3 pt 7 title \"parabolic motion\" \n");
    if((fp = fopen("result/1.log", "w")) == NULL){
        printf("ERROR: Cannot open file (result/test.dat)\n");
    } else {
        for(int i = 0; i < loop; x += dx, y += dy, z += dz, t += dt, i++){
            dvz = g * dt;
            vz = vz + dvz;
            dz = vz * dt;

            array[i].x = x;
            array[i].y = y;
            array[i].z = z;
            array[i].t = t;
            fprintf(pipe, "%lf, %lf, %lf\n", array[i].x, array[i].y, array[i].z);
            fprintf(fp, "%lf, %lf, %lf\n", array[i].x, array[i].y, array[i].z);
        }
        fclose(fp);
    }
    pclose(pipe);
    return 0;
}

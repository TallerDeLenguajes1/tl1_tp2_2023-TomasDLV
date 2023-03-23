#include <stdio.h>
#include <stdlib.h>
#define N 20

void main(){
    double vt[N];
    for ( int i = 0; i < N; i++)
    {
        vt[i]=1 + rand()%100;
        printf("%.2f   ",vt[i]);
    }
}




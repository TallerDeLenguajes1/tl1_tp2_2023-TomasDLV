#include <stdio.h>
#include <stdlib.h>
#define N 5
#define M 7

void main(){
    int i,j;
    int mt[N][M],*punt;
    punt = &mt[0][0];
    
    for ( i = 0; i < N; i++)
    {
        for ( j = 0; j < M; j++)
        {
            *punt = 1 + rand()%100;
            printf("%.2d   ",*punt);
            punt++;
        }
        printf("\n");
    }
}

#include <omp.h>
#include <stdio.h>
 
#define M 32
 
void main ()
{
     int i, j;
     int d1[M], d2[M], d3[M], res[M];
 
     for (i=0; i < M; i++)
     {
           d1[i] = i;
           d2[i] = i+2;
           d3[i] = i+5;
           res[i] = 0;
     }
 
     for (i=0; i < M; i++)
     {
           res[i] = d1[i] * d2[i] * d3[i];
     }
 
     printf("\nResult:\n");
     for (j=0; j < M; j++)
           printf("%d ", res[j]);
     printf("\n");
}

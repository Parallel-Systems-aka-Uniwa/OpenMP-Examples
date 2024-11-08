#include <omp.h>
#include <stdio.h>
 
#define M 32
#define CS 4
 
void main ()
{
     int i, j, chunk;
     int d1[M], d2[M], d3[M], res[M];
     chunk=CS;
 
     for (i=0; i < M; i++)
     {
           d1[i] = i;
           d2[i] = i+2;
           d3[i] = i+5;
           res[i] = 0;
     }
 
     #pragma omp parallel for schedule(static, chunk) shared(d1,d2,d3,res,chunk) private(i)
     for (i=0; i < M; i++)
     {
           res[i] = d1[i] * d2[i] * d3[i];
     }
     printf("\nResult:\n");
     for (j=0; j < M; j++)
           printf("%d ", res[j]);
     printf("\n");
}

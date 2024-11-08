#include <omp.h>
#include <stdio.h>
#define K 100
#define L 500
#define M 1000
 
int main ()
{
            int i, t;
            int a1[K];
            int a2[K];
            int aR[K];
            int b1[L];
            int b2[L];
            int bR[L];
            int c1[M];
            int c2[M];
            int cR[M];
 
            /* Αρχικοποιήσεις διανυσμάτων */
            for (i=0; i < K; i++)
            {
                        a1[i] = 2 * i;
                        a2[i] = i;
            }
            for (i=0; i < L; i++)
            {
                        b1[i] = 10 * i;
                        b2[i] = i;
            }
            for (i=0; i < M; i++)
            {
                        c1[i] = i + 1;
                        c2[i] = i;
            }
 
            #pragma omp parallel shared(a1,a2,aR,b1,b2,bR,c1,c2,cR) private(i)
            {
                        #pragma omp sections
                        {
                                    #pragma omp section
                                    for (i=0; i < K; i++)
                                                aR[i] = a1[i] - a2[i];
                                    #pragma omp section
                                    for (i=0; i < L; i++)
                                                bR[i] = b1[i] + b2[i];
                                    #pragma omp section
                                    for (i=0; i < M; i++)
                                                cR[i] = c1[i] * c2[i];
                        }  /* τέλος της διαταγής sections */
            }  /* τέλος της παράλληλης περιοχής */
 
            printf("Final Result Vectors:\n");
            for (t=0; t < 10; t++)
                        printf("aR[%d]=%d\t bR[%d]=%d\tcR[%d]=%d\n", t, aR[t], t, bR[t], t, cR[t]);
            printf("\n");
}

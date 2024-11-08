#include <omp.h>
#include <stdio.h>
#define N 10000

int main ()
{
            int tid, i, sum=0;
            omp_set_num_threads(8);

            #pragma omp parallel private(i, tid)
            {
                        tid = omp_get_thread_num();
                        for (i=0; i < N; i++)
                        {
                                    #pragma omp atomic
                                    sum=sum+i;
                        }
                        #pragma omp barrier

                        #pragma omp master
                        printf("Thread %d reports: Sum is %d\n", tid, sum);

                        #pragma omp barrier
                        for (i=0; i < N; i++)
                        {
                                    #pragma omp atomic
                                    sum=sum-i;
                        }
                        #pragma omp barrier

                        #pragma omp master
                        printf("Thread %d reports: Sum is %d - goodbye!\n", tid, sum);
            }
}

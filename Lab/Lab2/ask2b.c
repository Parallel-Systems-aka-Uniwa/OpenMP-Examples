#include <omp.h>
#include <stdio.h>
#define CHUNKSIZE 1
#define N 100

main ()
{
            int tid, i, chunk;
            int x=0;

            chunk =          CHUNKSIZE;

            omp_set_num_threads(4);

            #pragma omp parallel private(i, tid)
            {
                        tid = omp_get_thread_num();
                        #pragma omp for schedule(static,chunk)
                        for (i=0; i < N; i++)
                        {
                                    if (tid / 2 == 0)
                                    {
                                                #pragma omp critical (inc_x)
                                                {
                                                            x=x+1;
                                                }
                                                printf("Thread %d, added 1 -> x=%d\n", tid, x);
                                    }
                                    else
                                    {
                                                #pragma omp critical (inc_x)
                                                {
                                                            x=x-1;
                                                }
                                                printf("Thread %d, sub'ed 1 -> x=%d\n", tid, x);
                                    }
                        }
            }  /* Τερματισμός όλων των νημάτων */
            printf("x final value=%d\n", x);
}

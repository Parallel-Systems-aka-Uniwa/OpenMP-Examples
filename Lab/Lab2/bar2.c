#include <omp.h>
#include <stdio.h>
#define N 1000000000

main ()
{
	int tid, i;
	omp_set_num_threads(4);

	#pragma omp parallel private(i, tid)
	{
		tid = omp_get_thread_num();
		for (i=0; i < (tid+1)*N; i++)
		{ // do nothing
		}
		printf("Thread %d: work is done!\n", tid);
		//sleep(5);
		#pragma omp barrier
		printf("Thread %d: goodbye!\n", tid);
	}  /* Τερματισμός όλων των νημάτων */
}

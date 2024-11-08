#include <omp.h>
#include <stdio.h>

int main ()
{
	int i, j;

	// 1η απόπειρα: με 4 νήματα
	omp_set_num_threads(4);
	#pragma omp parallel for private(j)
	for (i = 0; i < 4; i++)
		for (j = 0; j < 100; j++)
			printf("Thread %d with (%d,%d)\n", omp_get_thread_num(), i, j);
}

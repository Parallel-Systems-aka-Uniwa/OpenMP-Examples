#include <omp.h>
#include <stdio.h>

int main ()
{
	int i, j;

	// 4η απόπειρα: 8 νήματα + collapse(1)
	omp_set_num_threads(8);
	#pragma omp parallel for private(j) collapse(1)
	for (i = 0; i < 4; i++)
		for (j = 0; j < 100; j++)
			printf("Thread %d with (%d,%d)\n", omp_get_thread_num(), i, j);
}

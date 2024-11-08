#include <omp.h>
#include <stdio.h>

int main ()
{
	int i, j;

	// 2η απόπειρα: με 8 νήματα
	omp_set_num_threads(8);
	#pragma omp parallel for private(j)
	for (i = 0; i < 4; i++)
		for (j = 0; j < 100; j++)
			printf("Thread %d with (%d,%d)\n", omp_get_thread_num(), i, j);
}

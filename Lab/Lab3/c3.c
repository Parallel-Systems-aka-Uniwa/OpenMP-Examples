#include <omp.h>
#include <stdio.h>

int main ()
{
	int i, j, n;

	// 3η απόπειρα: με 8 νήματα
	omp_set_num_threads(8);
	#pragma omp parallel for private(j)
	for(n=0; n<4*100; n++)
	{
		i=n/100;
		j=n%100;
		printf("Thread %d with (%d,%d)\n", omp_get_thread_num(), i, j);
	}
}

#include <omp.h>
#include <stdio.h>

int main()
{
	int tid, j;
	int tmp = 50;

	printf("Initially we get: %d\n", tmp);

	#pragma omp parallel private(tid)
	{
		tid = omp_get_thread_num();

		// private -> firstprivate -> lastprivate
		#pragma omp for lastprivate(tmp)
		for (j=0; j<1000; j++)
		{
			tmp += j;
			if (j==999) printf("tmp after=%d\n", tmp);
		}
	}
	printf("Finally we get: %d\n", tmp);
}

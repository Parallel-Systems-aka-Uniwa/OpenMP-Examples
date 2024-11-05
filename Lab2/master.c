#include <stdio.h>

int main(int argc, char *argv[])
{
	#pragma omp parallel
	{
		#pragma omp master
		{
			printf("Hello from %d\n", omp_get_thread_num());
		}
		#pragma omp single
		{
			printf("This is %d\n", omp_get_thread_num());
		}
		printf("Test %d\n", omp_get_thread_num());
	}
	return 0;
}

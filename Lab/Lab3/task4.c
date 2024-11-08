#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	#pragma omp parallel
	{
		#pragma omp single
		{
			printf("alpha ");
			#pragma omp task
			{
				printf("beta ");
			}
			#pragma omp task
			{
				printf("gamma ");
			}
		}
	}
	printf("\n");
	return(0);
}

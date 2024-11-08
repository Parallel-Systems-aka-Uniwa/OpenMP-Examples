#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	#pragma omp parallel
	{
		printf("alpha ");
		printf("beta ");
		printf("gamma ");
	}
	printf("\n");
	return(0);
}

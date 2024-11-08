#include <omp.h>
#include <stdio.h>

#define N 16

main ()
{
	int t, i, tid, chunk;
	int a[N], b[N], c[N];

	/* Αρχικοποίηση των δύο διανυσμάτων */
	for (i=0; i < N; i++)
		a[i] = b[i] = i * 2;

	tid = 0; //single thread
	for (i=0; i < N; i++)
	{
		printf("Thread %d computes iteration %d\n", tid, i);
		c[i] = a[i] + b[i];
	}

	printf("\nFinal Result Adding Vectors:\n");
	for (t=0; t < N; t++)
		printf("%d ", c[t]);
	printf("\n");
}

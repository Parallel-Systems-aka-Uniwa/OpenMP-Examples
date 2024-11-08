#include <omp.h>
#include <stdio.h>

int main ()
{
	int i, num_steps;
	double x, step, sum, aux, pi;
	double ctime1, ctime2;

	omp_set_num_threads(4);

	num_steps = 1000000000;
	x=0;
	sum = 0.0;
	aux = 0.0;
	step = 1.0/(double) num_steps;

	ctime1 = omp_get_wtime();
	#pragma omp parallel private(i,x,aux) shared(sum)
	{
		#pragma omp for schedule(static)
		for (i=0; i<num_steps; i=i+1)
		{
			x=(i+0.5)*step;
			aux+=4.0/(1.0+x*x);
		}
		#pragma omp critical (p_sum)
		sum = sum + aux;
	}
	pi=step*sum;
	ctime2 = omp_get_wtime();
	printf("\nPi = %f  Time = %f \n", pi, ctime2-ctime1);
}

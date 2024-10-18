#include <omp.h>
#include <stdio.h>

#define CHUNKSIZE 2
#define N     16

main ()  
{

int t, i, tid, chunk;
int a[N], b[N], c[N];

/* Αρχικοποίηση των δύο διανυσμάτων */
for (i=0; i < N; i++)
  a[i] = b[i] = i * 2;

omp_set_num_threads(4);

/* Καθόρισε σε ομάδες των πόσων επαναλήψεων, θα γίνει η διαμοίραση του for-loop στα τρέχοντα νήματα */
chunk = CHUNKSIZE;

#pragma omp parallel shared(a,b,c,chunk) private(i,tid)
  {
  tid = omp_get_thread_num();
  #pragma omp for schedule(static,chunk) 
  for (i=0; i < N; i++)
    {
     if (i==0 || i==1) {
        sleep(5);
        printf("Thread %d computes iteration %d\n", tid, i);
        c[i] = a[i] + b[i];  
     }
     else {
        sleep(1);
        printf("Thread %d computes iteration %d\n", tid, i);
        c[i] = a[i] + b[i];  
    }

  }  /* Τερματισμός όλων των νημάτων */

}

printf("\nFinal Result Adding Vectors:\n");
for (t=0; t < N; t++) 
 printf("%d ", c[t]); 
printf("\n");
}


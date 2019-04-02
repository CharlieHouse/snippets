#include <omp.h>
#include <stdio.h>
int main(void) {
	float a=5;

	printf("Hello Global\n\n");
    
    #pragma omp parallel
    {
    printf("Hello from thread %d, nthreads %d\n", omp_get_thread_num(), omp_get_num_threads());
    
    
    printf("In this thread, a = %f\n",a);
    a+=1;	/* This might be introducing a race condition....*/
	}

	printf("Hello Global\n\n");
	printf("a now equals %f\n",a);
    return 0;
}

 /* export OMP_NUM_THREADS=4 controls how many threads to setup */
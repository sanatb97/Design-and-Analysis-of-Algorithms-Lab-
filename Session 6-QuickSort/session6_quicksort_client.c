#include <stdlib.h>
#include <stdio.h>
#include "session6_quicksort.h"
#include <time.h>
double time_elapsed(struct timespec *start, struct timespec *end);
int main()
{
	int n,i;
	struct timespec start;
	struct timespec end;
	scanf("%d",&n);
	
	Data *A=(Data *)malloc(n*sizeof(Data));
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&(A[i].id),&(A[i].value));
	}
	clock_gettime(CLOCK_REALTIME, &start);
	QuickSort(A,n);
	clock_gettime(CLOCK_REALTIME, &end);
	for(i=0;i<n;i++)
		printf("%d %d\n",A[i].id,A[i].value);
	printf("%lf sec\n", time_elapsed(&start, &end));
	return 0;
	
} 
double time_elapsed(struct timespec *start, struct timespec *end) {
	double t;
	t = (end->tv_sec - start->tv_sec); // diff in seconds
	t += (end->tv_nsec - start->tv_nsec) * 0.000000001; //diff in microseconds
	return t;

}
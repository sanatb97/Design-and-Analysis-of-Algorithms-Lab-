#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "session5_mergesort_binsearch.h"
double time_elapsed(struct timespec *start, struct timespec *end);
int main()
{
	int n,key,i,id,value,index;
	struct timespec start1;
	struct timespec end1;
	struct timespec start2;
	struct timespec end2;
	scanf("%d",&n);
	Data *a=(Data*)malloc(n*sizeof(Data));
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&id,&value);
		a[i].id=id;
		a[i].value=value;
	}
	scanf("%d",&key);
	clock_gettime(CLOCK_REALTIME, &start1); 
	MergeSort(a,n);
	clock_gettime(CLOCK_REALTIME, &end1); 


	clock_gettime(CLOCK_REALTIME, &start2); 
    index=BinarySearch(a,n,key);
    clock_gettime(CLOCK_REALTIME, &end2); 
	for(i=0;i<n;i++)
	{
		printf("%d %d\n",a[i].id,a[i].value);
	}
	if(index==-1)
		printf("NOT FOUND\n");
	else
		printf("%d %d %d\n",index,a[index].id,a[index].value);
	printf("%lf sec\n", time_elapsed(&start1, &end1)+time_elapsed(&start2, &end2));
	return 0;

}

double time_elapsed(struct timespec *start, struct timespec *end) {
	double t;
	t = (end->tv_sec - start->tv_sec); // diff in seconds
	t += (end->tv_nsec - start->tv_nsec) * 0.000000001; //diff in nanoseconds
	return t;
}
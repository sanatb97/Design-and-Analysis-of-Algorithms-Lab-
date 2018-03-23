#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "session7_sort.h"
double time_elapsed(struct timespec *start, struct timespec *end);
void main()
{
	int n,i,score;
	long int serialno,c1,c2,c3,c4,c5;
	struct timespec start1;
	struct timespec end1;
	struct timespec start2;
	struct timespec end2;
	struct timespec start3;
	struct timespec end3;
	struct timespec start4;
	struct timespec end4;
	struct timespec start5;
	struct timespec end5;
	scanf("%d",&n);
	Record *A=(Record*)malloc(n*sizeof(Record));

	for(i=0;i<n;i++)
	{
		scanf("%ld %d",&A[i].serialnumber,&A[i].score);
		
		
	}
	clock_gettime(CLOCK_REALTIME, &start1);
	c1=InsertionSort(A,n);
	clock_gettime(CLOCK_REALTIME, &end1);
	clock_gettime(CLOCK_REALTIME, &start2);
	c2=BubbleSort(A,n);
	clock_gettime(CLOCK_REALTIME, &end2);
	/*for(i=0;i<n;i++)
	{
		printf("%ld\n",A[i].serialnumber);
	}*/
	clock_gettime(CLOCK_REALTIME, &start3);
	c3=SelectionSort(A,n);
	clock_gettime(CLOCK_REALTIME, &end3);
	clock_gettime(CLOCK_REALTIME, &start4);
	c4=MergeSort(A,n);
	clock_gettime(CLOCK_REALTIME, &end4);
	clock_gettime(CLOCK_REALTIME, &start5);
	c5=QuickSort(A,n);
	clock_gettime(CLOCK_REALTIME, &end5);
	
	printf("Insertion Sort: %ld %lf\n",c1,time_elapsed(&start1,&end1));
	
	printf("Bubble Sort: %ld %lf\n",c2,time_elapsed(&start2,&end2));

	printf("Selection Sort: %ld %lf\n",c3,time_elapsed(&start3,&end3));

	printf("Merge Sort: %ld %lf\n",c4,time_elapsed(&start4,&end4));
	
	
	printf("Quick Sort: %ld %lf\n",c5,time_elapsed(&start5,&end5));

	/*for(i=0;i<n;i++)
	{
		printf("%ld\n",A[i].serialnumber);
	}*/



free (A);

}
double time_elapsed(struct timespec *start, struct timespec *end) {
	double t;
	t = (end->tv_sec - start->tv_sec); // diff in seconds
	t += (end->tv_nsec - start->tv_nsec) * 0.000000001; //diff in microseconds
	return t;

}
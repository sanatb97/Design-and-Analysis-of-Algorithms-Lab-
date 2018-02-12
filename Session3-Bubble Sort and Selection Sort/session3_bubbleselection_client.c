#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "session3_bubbleselection.h"
double time_elapsed(struct timespec *start, struct timespec *end);
int main(int argc, char const *argv[])
{
	int n; //input size
	scanf("%d",&n);
	int i;
	int id,value;
	Data *A,*A1,*A2,*B;
	A=(Data*)malloc(sizeof(Data));
	B=(Data*)malloc(sizeof(Data));
	A1=(Data*)malloc(sizeof(Data));
	A2=(Data*)malloc(sizeof(Data));
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&id,&value);
		A[i].id=id;
		A[i].value=value;
		B[i].id=id;
		B[i].value=value;

	}
	
	int k;
	scanf("%d",&k);
	
	struct timespec start1,start2;
	struct timespec end1,end2;
	
	
	clock_gettime(CLOCK_REALTIME, &start1);
	A1=BubbleSort(A,n,k);
	clock_gettime(CLOCK_REALTIME, &end1);
	
	clock_gettime(CLOCK_REALTIME, &start2);
	A2=SelectionSort(B,n,k);
	clock_gettime(CLOCK_REALTIME, &end2);
	
	for(i=0;i<n;i++)
	{	
		printf("%d %d\n",A1[i].id,A1[i].value);
	}
	for(i=0;i<n;i++)
	{
	
		printf("%d %d\n",A[i].id,A[i].value);
	}
	
	
	
	
	for(i=0;i<n;i++)
	{	
		printf("%d %d\n",A2[i].id,A2[i].value);
	}
	for(i=0;i<n;i++)
	{
		printf("%d %d\n",B[i].id,B[i].value);
	}
	printf("%lf sec\n", time_elapsed(&start1, &end1));
	printf("%lf sec\n", time_elapsed(&start2, &end2));
	
	
	return 0;
}

double time_elapsed(struct timespec *start, struct timespec *end) 
{
	double t;
	t = (end->tv_sec - start->tv_sec); // diff in seconds
	t += (end->tv_nsec - start->tv_nsec) * 0.000000001; //diff in nanoseconds
	return t;
}
	
	
	
	
	

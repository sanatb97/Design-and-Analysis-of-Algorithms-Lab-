#include <stdio.h>
#include <stdlib.h>
#include "session12_WarshallsFloyds.h"
#include <time.h>
double time_elapsed(struct timespec *start, struct timespec *end);
int main()
{
	struct timespec start1;
	struct timespec end1;
	struct timespec start2;
	struct timespec end2;
	int n,i,j;
	scanf("%d",&n);
	int **graph=(int**)malloc(n*sizeof(int*));
	for(i=0;i<n;i++)
		graph[i]=(int*)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&graph[i][j]);
	printf("\n");
	clock_gettime(CLOCK_REALTIME, &start1);
	transitive_closure_warshalls(graph,n);
	clock_gettime(CLOCK_REALTIME, &end1);
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%d ",graph[i][j]);
		
		printf("\n");
	}	
	scanf("%d",&n);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&graph[i][j]);
	printf("\n");
	clock_gettime(CLOCK_REALTIME, &start2);
	all_pairs_shortest_path_distances_floyds(graph,n);
	clock_gettime(CLOCK_REALTIME, &end2);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%d ",graph[i][j]);
		
		printf("\n");
	}
	//printf("%lf sec\n",time_elapsed(&start1,&end1));
	//printf("%lf sec\n",time_elapsed(&start2,&end2));

	
return 1;
}

double time_elapsed(struct timespec *start, struct timespec *end) {
	double t;
	t = (end->tv_sec - start->tv_sec); // diff in seconds
	t += (end->tv_nsec - start->tv_nsec) * 0.000000001; //diff in microseconds
	return t;
	}
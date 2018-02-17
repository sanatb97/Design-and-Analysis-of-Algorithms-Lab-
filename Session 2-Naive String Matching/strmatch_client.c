#include <stdio.h>
#include <stdlib.h>
#include <time.h>
double time_elapsed(struct timespec *start, struct timespec *end);
void main()
{
	int *index=(int *)malloc(sizeof(int));
	
	char text[1000000];

	int t;
	scanf("%[^\n]",text);
	scanf("%d",&t);
	int indices[t];
	int i;
	int **patterns=(int **)malloc(10*sizeof(int *));
	for(i=0;i<10;i++)
	{
		patterns[i]=(int *)malloc(1000000*sizeof(int));
	}
	for(i=0;i<t;i++)
	{
		scanf("%[^\n]",patterns[i]);

	}
	for(i=0;i<t;i++)
	{
		*index=-1;
		stringmatch(patterns[i],text,index);
		printf("%d\n",*index);
		indices[i]=*index;




	}

}

double time_elapsed(struct timespec *start, struct timespec *end) {
	double t;
	t = (end->tv_sec - start->tv_sec); // diff in seconds
	t += (end->tv_nsec - start->tv_nsec) * 0.000000001; //diff in nanoseconds
	return t;
}
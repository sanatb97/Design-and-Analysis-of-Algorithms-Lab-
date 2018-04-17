#include <stdio.h>
#include <stdlib.h>
#include "session10_dcs.h"

int main()
{
	int n;
	scanf("%d",&n);
	int *A=(int *)malloc(n*sizeof(int));
	int *A1=(int *)malloc(n*sizeof(int));
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
	}
	for(i=0;i<n;i++)
		A1[i]=A[i];
	DistributionCountingSorting(A,n);
	MergeSort(A1,n);
	for(i=0;i<n;i++)
	{
		printf("%d\n",A1[i]);
	}
	
	return 0;
}

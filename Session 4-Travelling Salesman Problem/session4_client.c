#include <stdio.h>
#include <stdlib.h>

#include "session4_tsp.h"

void main()
{
	int n;
	scanf("%d",&n);
	int i,j;
	int **cost_matrix=(int**)malloc(n*sizeof(int*));
	for(i=0;i<n;i++)
	{
		cost_matrix[i]=(int*)malloc(sizeof(int));

	}
	for (i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&cost_matrix[i][j]);

		}
	}
	int min_cost=tsp(cost_matrix,n);
	printf("%d\n",min_cost);
}

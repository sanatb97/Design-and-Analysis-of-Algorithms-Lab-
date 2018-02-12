#include "session4_tsp.h"
#include <stdlib.h>
// Get the next permutation in lexicographic order
int get_next_permutation(int *permutation, int n) {
	int i;
	int j;
	int k;
	int temp_int;
	int swaps;

	//find i
	for(i = n-2; i >= 0; i--) {
		if(permutation[i] < permutation[i+1]) {
			break;
		}
	}
	if(i == -1) {
		return 0;
	}

	for(j = i+1; j < n; j++) {
		if(permutation[j] < permutation[i]) {
			break;
		}
	}
	j--;

	temp_int = permutation[i];
	permutation[i] = permutation[j];
	permutation[j] = temp_int;

	//printf("DEBUG*i=%d,j=%d*", i, j); print_permutation(permutation, n);
	swaps = (n-1-i)/2;	
	for(k = 0; k < swaps; k++) {
		temp_int = permutation[i+1+k];
		permutation[i+1+k] = permutation[n-1-k];
		permutation[n-1-k] = temp_int;
	}
	return 1;
}

int tsp(int** graph, int n)
{
	int mincost=10000,cost;
	int *permutation=(int *)malloc(n*sizeof(int));

	int i;
	for(i=0;i<n-1;i++)
	{
		permutation[i]=i+1;
	}
	do
	{

		cost=graph[0][permutation[0]];
		cost=cost+graph[permutation[n-1]][0];
		for(i=0;i<n-2;i++)
		{
			cost=cost+graph[permutation[i]][permutation[i+1]];

		}
		if (cost<mincost)
			mincost=cost;
	}

		while(get_next_permutation(permutation,n));

		return mincost;

	}

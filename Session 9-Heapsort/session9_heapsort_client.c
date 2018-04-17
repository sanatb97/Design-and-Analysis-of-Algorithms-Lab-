
#include "session9_heapsort.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void main()
{
	int n;
	
	Data * A;
	scanf("%d",&n);
	A=(Data*)malloc((n+1)*sizeof(Data));

	int i;
	for(i=1;i<=n;i++)
	{
		scanf("%d %d",&A[i].id,&A[i].value);
		
	}
	HeapSort(A,n);
	for(i=1;i<=n;i++)
	{
		printf("%d %d\n",A[i].id,A[i].value);

	}
}
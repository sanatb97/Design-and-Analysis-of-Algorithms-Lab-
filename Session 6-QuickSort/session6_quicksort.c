#include <stdlib.h>
#include "session6_quicksort.h"


int Partition(Data * A, int n)
{
	int p=A[0].id,i=1,j=n-1;
	Data t;

	while(i<=j)
	{
		while (i<=j && A[i].id<p)
			i=i+1;
		while (i<=j && A[j].id>p)
			j-=1;
		if(i<j)
		{
			t=A[i];
			A[i]=A[j];
			A[j]=t;
			i=i+1;
			j=j-1;
		}

	}
	t=A[j];
	A[j]=A[0];
	A[0]=t;
	return j;
}

void QuickSort(Data* A, int n)
{
	
	
	if(n<=2)
			return;
	

	
	
	int s=Partition(A,n);
	
	QuickSort(A,s);
	QuickSort(A+s+1,n-s-1);
	
	 
}
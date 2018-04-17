#include "session9_heapsort.h"

void Heapify(Data *A,int n,int k)
{
	if(2*k>n)
		return;
	int j=2*k;
	Data temp;
	if(j+1<=n)
		if(A[j+1].id>A[j].id)
			++j;
		if(A[j].id>A[k].id)
			{
				temp=A[j];
				A[j]=A[k];
				A[k]=temp;
				Heapify(A,n,j);
			}
}



void HeapBottomUp(Data * A, int n)
{
	if (n<=1)
		return;
	for(int i=n/2;i>=1;i--)
		Heapify(A,n,i);
}




void HeapSort(Data* A, int n)
{
	Data temp;
	HeapBottomUp(A,n);
	int i;
	for(i=n;i>=2;i--)
	{
		temp=A[1];
		A[1]=A[i];
		A[i]=temp;
		Heapify(A,i-1,1);

	}
}
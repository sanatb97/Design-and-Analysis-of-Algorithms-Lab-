#include "session5_mergesort_binsearch.h"
#include <stdlib.h>

void Merge(Data *A,Data *a1,Data *a2,int n,int m)
{
	int i=0,j=0,k=0;
	while(i<m && j<(n-m))
		{
			if(a1[i].value<=a2[j].value)
				A[k++]=a1[i++];
			else
				A[k++]=a2[j++];
		}
		while (i<m)
			A[k++]=a1[i++];
		while(j<n)
			A[k++]=a2[j++];
 

}


void MergeSort(Data* A, int n)
{ 
	int i;
	if(n<2)
		return;
	int m=n/2;
	Data *a1=(Data*)malloc(m*sizeof(Data));
	Data *a2=(Data*)malloc((n-m)*sizeof(Data));
	for(i=0;i<m;i++)
	{
		a1[i]=A[i];

	}
	for(i=m;i<n;i++)
	{
		a2[i-m]=A[i];
	}

	MergeSort(a1,m);
	MergeSort(a2,n-m);

	Merge(A,a1,a2,n,m);

}


int BinarySearch(Data * A, int n, int key_value)
{
	int lb=0,ub=n-1,mid;
	while(ub>=lb)
	{
		mid=(ub+lb)/2;
		if (A[mid].value==key_value)
		{
			
			return mid;
			
		}
		if(A[mid].value<key_value)
			lb=mid+1;
		else
			ub=mid-1;
	}
	return -1;
}

#include <stdlib.h>
#include "session10_dcs.h"
int max(int *a,int n)
{
	int m=a[0];
	for(int i=0;i<n;i++)
		if(a[i]>m)
			m=a[i];
	return m;
}

int min(int *a,int n)
{
	int m=a[0];
	for(int i=0;i<n;i++)
	{
		if(a[i]<m)
			m=a[i];
	}
	return m;
}


void DistributionCountingSorting(int* A, int n)
{

	int *S=(int *)malloc(sizeof(int)*n);

	int l=min(A,n);
	int u=max(A,n);
	int *D=(int *)malloc(sizeof(int)*(u-l+1));
	int i,j;
	
	for(i=0;i<=u-l;i++)
		D[i]=0;

	for(i=0;i<n;i++)
		D[A[i]-l]=D[A[i]-l]+1;
	
	for(i=1;i<=u-l;i++)
		D[i]=D[i-1]+D[i];
	for(i=n-1;i>=0;i--)
	{
		j=A[i]-l;
		S[D[j]-1]=A[i];
		D[j]=D[j]-1;

	}

for(i=0;i<n;i++)
{
	A[i]=S[i];
}



}

void Merge(int *A,int m,int n)
{
	int i=0;
	int j=m;
	int k=0;
	int *B=(int *)malloc(n*sizeof(int));
	while(i<m && j<n)
	{
		if(A[i]<=A[j])
		{
			B[k++]=A[i++];
		}
		else
			B[k++]=A[j++];

	}
	if(j==n)
		while(i<m)
		{
			B[k++]=A[i++];

		}
		else
		{
			while(j<n)
				B[k++]=A[j++];
		}
		for(i=0;i<n;i++)
			A[i]=B[i];

}

void MergeSort(int* A, int n)
{ 
	int i;
	if(n<2)
		return;
	int m=n/2;
	
	/*for(i=m;i<n;i++)
	{
		a2[i-m]=A[i];
	}*/

	MergeSort(A,m);
	MergeSort(A+m,n-m);

	Merge(A,m,n);

	
}
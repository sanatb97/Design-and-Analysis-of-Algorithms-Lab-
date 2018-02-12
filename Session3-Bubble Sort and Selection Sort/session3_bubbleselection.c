#include "session3_bubbleselection.h"
#include<stdlib.h>
#include<stdio.h>

 
Data* BubbleSort(Data* A, int n, int k)
{
	int i,j;
	Data temp;
	int noSwaps;
	Data *A1=(Data*)malloc(n*sizeof(Data));
	k--;
	if(n==1)
	{
		A1[0].value=A[0].value;
		A1[0].id=A[0].id;
		return A1;
	}
	
	

	for(i=0;i<n-1;i++)
	{
		noSwaps=1;
		

	
		for(j=0;j<=(n-2-i);j++)
		{
			if(A[j].value>A[j+1].value)
			{
				temp=A[j];
				A[j]=A[j+1];
				A[j+1]=temp;
				noSwaps=0;
			}			
		}
		if(i==k)
			for(int l=0;l<n;l++)
				{
					A1[l].value=A[l].value;
					A1[l].id=A[l].id;
				}
		if(noSwaps==1)
			return A1;
	}
	
	return A1;
	
}



Data* SelectionSort(Data * A, int n, int k)
{
	int i,min;
	Data temp;
	int j;
	--k;
	Data *A2=(Data*)malloc(n*sizeof(Data));
	if(n==1)
	{
		A2[0].value=A[0].value;
		A2[0].id=A[0].id;
		return A2;
	}
		for(i=0;i<=(n-2);i++)
	{
		
		min=i;
		for(j=i+1;j<=(n-1);j++)
		{
			if(A[j].value<A[min].value)
				min=j;
		}
		temp=A[i];
		A[i]=A[min];
		A[min]=temp;
		if(i==k)
		{
			for(int m=0;m<n;m++)
			{
				A2[m].value=A[m].value;
				A2[m].id=A[m].id;
			}
			
		}
	}
	return A2;
}




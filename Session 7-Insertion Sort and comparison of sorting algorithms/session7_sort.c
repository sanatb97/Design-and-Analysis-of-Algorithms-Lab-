#include <stdlib.h>
#include "session7_sort.h"


#include <stdio.h>

long int InsertionSort(Record* A, int n){
	int i,j;
	Record temp;
	static long int count=0;
	for (i=1;i<n;i++){
		temp=A[i];
		j=i-1;
		while(j>=0 && A[j].serialnumber>temp.serialnumber)
		{
			++count;
			A[j+1]=A[j];
			j=j-1;
			
		}
		A[j+1]=temp;
		if(j>=0)
		count++;
	}
	return count ;

}

long int BubbleSort(Record* A, int n)
{
    int noSwaps = 0,i,j;
    Record temp;
    long int numberOfComparisons=0;
    for(i=0;i<n-1;i++)
    {
        noSwaps = 1; 
        ++numberOfComparisons;
        for(j=0;j<=n-2-i;j++)
        {
            ++numberOfComparisons;
            if(A[j].serialnumber > A[j+1].serialnumber)
            {
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
                noSwaps = 0;
            }
        }
         ++numberOfComparisons;
        if(noSwaps == 1) 
        	{
        		++numberOfComparisons;
        		return numberOfComparisons;
        	}
    }
    return numberOfComparisons;
}

long int SelectionSort(Record * A, int n)
{
	int i,min;
	Record temp;
	int j;
	long int count=0;
	
	for(i=0;i<=(n-2);i++)
	{
		
		min=i;
		for(j=i+1;j<=(n-1);j++)
		{
			count++;
			if(A[j].serialnumber<A[min].serialnumber)
			{
				
				min=j;
			}
		}
		temp=A[i];
		A[i]=A[min];
		A[min]=temp;
		
	}
	return count;
}





int Partition(Record * A, int n,long int* count)
{
	
	int p=A[0].serialnumber,i=1,j=n-1;
	Record t;

	while(i<=j && (++(*count)))
	{
		while (i<=j && A[i].serialnumber<p)
			i=i+1;
		while (i<=j && A[j].serialnumber>p)
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
	++(*count);
	t=A[j];
	A[j]=A[0];
	A[0]=t;
	
	return j;
}

long int QuickSort(Record* A, int n)
{
	
	static long int count=0;
	if (n>1)
	{

	
	
	int s=Partition(A,n,&count);
	
	
	QuickSort(A,s);
	
	QuickSort(A+s+1,n-s-1);

	}
	return count-1;
	
	 
}
long int Merge(Record* A, int n,int m)
{
    long int numberOfComparisons=0;
    Record * B = (Record*)malloc(sizeof(Record)*n);
    int i=0,j=m,k=0,cp;
    while(i<m && j<n)
    {       ++numberOfComparisons;
            if(A[i].serialnumber <= A[j].serialnumber)
                B[k++]=A[i++];
            else
                B[k++] = A[j++];
    }
    if(j==n)
    {
        for(cp = i;cp<m-1;cp++)
        {
            B[k++]=A[cp]; 
        }
    }
    else
    {
        for(cp = j;cp<n-1;cp++)
        {
            B[k++]=A[cp];
        }
    }
    for(i=0;i<n;i++)
    {
        A[i] = B[i];
    }
    return numberOfComparisons;
}

long int MergeSort(Record* A, int n)
{
    long int numberOfComparisons=0;
    if(n<=1)
        return numberOfComparisons;
    int m = n/2;
    numberOfComparisons=MergeSort(A,m);
    numberOfComparisons+=MergeSort(&A[m],n-m);
    numberOfComparisons+=Merge(A,n,m);
    return numberOfComparisons;
}

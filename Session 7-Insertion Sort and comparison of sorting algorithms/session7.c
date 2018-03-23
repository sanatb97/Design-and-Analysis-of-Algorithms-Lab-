#include "session7_sort.h"
//#include<stdio.h>
#include<stdlib.h>
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
		
	}
	return count ;

}

long int BubbleSort(Record* A, int n)
{
	int i,j,noswaps;
	Record temp;
	long int count=0;
	for (i=0;i<n-1;i++)
	{
		noswaps=1;
		for(j=0;j<n-1-i;j++)
		{
			++count;
			if(A[j].serialnumber >A[j+1].serialnumber)
			{
				temp=A[j];A[j]=A[j+1];A[j+1]=temp;
				noswaps=0;
				}
			if(noswaps==1)
				return count;
		}
		
	}
	return count;
}

long int SelectionSort(Record* A, int n)
{
	Record temp;
	int min,i,j;
	long int count=0;
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			++count;
			if(A[j].serialnumber < A[min].serialnumber)
				min=j;
			
		}
		temp=A[i];A[i]=A[min];A[min]=temp;
		
		
	}
	return count;
}

long int  QuickSort(Record* A, int n){
	static long int count=1;
	
	int m;
	if(n>1)
	{
		m=Partition(A,n,&count);
		count+=QuickSort(A,m);
		count+=QuickSort(A+m+1,n-m-1);
		
	}
	return count-1;
};
int Partition(Record* A, int n, long int *count){
	int j=n-1,z,i=1,p=0;
	Record t;
	if(A[0].serialnumber<A[n/2].serialnumber)
		if(A[n/2].serialnumber<A[n-1].serialnumber)
			{t=A[0];A[0]=A[n/2];A[n/2]=t;}
	else(A[0].serialnumber<A[n-1].serialnumber)
		;
		if(A[n-1].serialnumber<A[n/2].serialnumber)
			{t=A[0];A[0]=A[n-1];A[n-1]=t;}
	

	
	while(i<=j && ++(*count)){
		while(i<=j && A[i].serialnumber<A[p].serialnumber&& ++(*count))
		{
			i++;
		}
		while(j>=i && A[j].serialnumber>A[p].serialnumber )
		{
			j--;
			
		}
		
		if(i<j){
			t=A[i];A[i]=A[j];A[j]=t;
			i++;
			j--;
			
		}
	}
//	printf(" ");
	t=A[p];A[p]=A[j];A[j]=t;
	
	return j;
	
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

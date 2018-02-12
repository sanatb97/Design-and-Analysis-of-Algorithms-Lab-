// Client code for session1_seq_search.c

#include <stdio.h>
#include <stdlib.h>
#include <time.h> //link with -lrt

#include "session1_seq_search.h"

//returns the duration from start to end times in sec
double time_elapsed(struct timespec *start, struct timespec *end);

int main(int argc, char const *argv[]) {
	int n; //size of the array
	int *arr; //array of size n
	int key; //key to be searched
	int res; //location of key in arr
	struct timespec start;
	struct timespec end;
	int i;

	scanf("%d", &n);
	arr = (int *) malloc(n * sizeof(n));

	for (i = 0; i < n; ++i) {
		scanf("%d", &arr[i]);
	}
	scanf("%d", &key);

	clock_gettime(CLOCK_REALTIME, &start); //start timestamp
	res = seqsearch(arr, n, key); //to get the first occurrence of key in arr
	clock_gettime(CLOCK_REALTIME, &end); //end timestamp

	printf("%d\n", res);
	printf("%lf sec\n", time_elapsed(&start, &end));
	free(arr);
	return 0;
}

//returns the duration from start to end times in sec
double time_elapsed(struct timespec *start, struct timespec *end) {
	double t;
	t = (end->tv_sec - start->tv_sec); // diff in seconds
	t += (end->tv_nsec - start->tv_nsec) * 0.000000001; //diff in nanoseconds
	return t;
}

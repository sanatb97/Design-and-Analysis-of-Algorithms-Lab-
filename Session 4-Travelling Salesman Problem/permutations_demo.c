#include <stdio.h>
#include <stdlib.h>

int get_next_permutation(int *permutation, int n);
void print_permutation(int *permutation, int n);

int main() {
	int n;//permutation of n symbols
	int i; //loop index
	int *permutation; // permutation array

	scanf("%d", &n); //n > 1
	permutation = (int *) malloc(n * sizeof(int));

	//first permutation
	for(i = 0; i < n; i++) {
		permutation[i] = i;
	}

	//do while there is a next permutation in lexicographic order
	do {
		print_permutation(permutation, n);
	} while (get_next_permutation(permutation, n));

	return 0;
}

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

void print_permutation(int *permutation, int n) {
	int i;
	printf("[");
	for(i = 0; i < n-1; i++) {
		printf("%d, ", permutation[i]);
	}
	printf("%d]\n", permutation[n-1]);
}

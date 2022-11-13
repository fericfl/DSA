#include <stdio.h>

void insert_sort(int A[], int N) {
	int i, j, key;
	for (i = 1; i < N; i++) {
		key = A[i];
		j = i - 1;

		while (j >= 0 && A[j] > key) {
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = key;
	}
}

void print_array(int A[], int N) {
	int i;
	for (i = 0; i < N; i++) {
		printf("%d ", A[i]);
	}
	printf("\n");
}

int main() {
	int A[] = { 12, 11, 13, 5, 6 };
	int N = sizeof(A) / sizeof(A[0]);

	insert_sort(A, N);
	print_array(A, N);

	return 0;
}
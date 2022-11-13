#include <stdio.h>
#include <stdlib.h>


void insertSort(int A[], int N) {
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

void selectionSort(int B[], int N) {
	int i, j, min_index;
	int aux;
	for (i = 0; i < N - 1; i++) {
		min_index = i;
		for (j = i + 1; j < N; j++)
			if (B[j] < B[min_index])
				min_index = j;
		if (min_index != i) {
			aux = B[min_index];
			B[min_index] = B[i];
			B[i] = aux;
		}
	}
}

void printArray(int A[], int N) {
	int i;
	for (i = 0; i < N; i++)
		printf("%d ", A[i]);
	printf("\n");
}

int main() {
	FILE* f = fopen("test.txt", "r");
	if (!f)
		printf("File cannot be opened!\n");
	int N;
	if (fscanf(f, "%d", &N) == 0)
		return -1;

	int A[100];
	int i = 0;
	while (fscanf(f, "%d", A[i] != 0) && i < N) {
		i++;
	}

	insertSort(A, N);

	fclose(f);
}
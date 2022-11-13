#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

int partition(int A[], int low, int high) {
    int pivot = A[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (A[j] < pivot) {
            i++;
            swap(&A[i], &A[j]);
        }
    }
    swap(&A[i + 1], &A[high]);
    return (i + 1);
}

void quicksort(int A[], int low, int high) {
    if (low < high) {
        int p_index = partition(A, low, high);

        quicksort(A, low, p_index - 1);
        quicksort(A, p_index + 1, high);

    }
}

void printArray(int A[], int size) {
    for (int i = 0; i < size; i++) {
        printf ("%d ", A[i]);
    }
    printf("\n");
}

int main() {
    FILE* f;
    f = fopen("text.txt", "r");
    if(!f) {
        printf("Cannot open file!\n");
        return -1;
    }
    else
        printf("File opened!\n");
    
    int size;
    if (!(fscanf(f, "%d", &size)))
        return -2;
    
    int A[1000];

    int i = 0;
    while (fscanf(f, "%d", &A[i]))
        i++;

    printArray(A, size);

    quicksort(A, A[0], A[size-1]);

    printArray(A, size);

    return 0;
}
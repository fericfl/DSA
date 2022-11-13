#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

int shellSort(int A[], int size) {
    for (int middle = size / 2; middle > 0; middle /= 2) {
        for (int i = middle; i < size; i++) {
            int aux = A[i];
            int j;
            for (j = i; j >= middle && A[j - middle] > aux; j -= middle) {
                A[j] = A[j - middle];
            }
            A[j] = aux;
        }
    }
    return 0;
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
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main() {
    FILE* f;
    f = fopen("text.txt", "r");
    if (!f) {
        printf("Cannot open file!\n");
        return -1;
    }
    else
        printf("File opened!\n");

    int size;
    if (!(fscanf(f, "%d", &size)))
        return -2;

    int A[100];
    int A2[100];

    int i = 0;
    for (i = 0; i < size; i++) {
        fscanf(f, "%d", &A[i]);
        A2[i] = A[i];
    }

    time_t start1=0, start2=0, end1, end2;
    
    

    printf("The array looks like this:\n");
    printArray(A, size);

    printf("Quicksort:\n");
    start1 = time(NULL);
    quicksort(A, 0, size - 1);
    end1 = time(NULL);
    printArray(A, size);
    printf("Time taken: %.2f seconds\n", difftime(end1,start2));

    printf("ShellSort:\n");
    start2 = time(NULL);
    shellSort(A2, size);
    end2 = time(NULL);
    printArray(A2, size);
    printf("Time taken: %.2f seconds\n", difftime(end2, start2));

    fclose(f);
    return 0;
}
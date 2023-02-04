#include <stdio.h>
#define MAX_SIZE 100
int arr[MAX_SIZE];
int size = 0;
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(int i, int n) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(largest, n);
    }
}
void buildMaxHeap(int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(i, n);
    }
}
void heapSort(int n) {
    buildMaxHeap(n);
    for (int i = n - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(0, i);
    }
}
void insert(int element) {
    if (size == MAX_SIZE) {
        printf("Array is full, insertion not possible\n");
    } else {
        arr[size] = element;
        size++;
    }
}
int main() {
    insert(10);
    insert(50);
    insert(30);
    insert(40);
    printf("Before sorting: \n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    heapSort(size);
    printf("After sorting: \n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

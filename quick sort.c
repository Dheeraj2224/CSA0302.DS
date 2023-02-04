#include <stdio.h>
#define MAX_SIZE 100
int arr[MAX_SIZE];
int size = 0;
int partition(int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}
void quickSort(int low, int high) {
    if (low < high) {
        int pi = partition(low, high);
        quickSort(low, pi - 1);
        quickSort(pi + 1, high);
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
    quickSort(0, size - 1);
    printf("After sorting: \n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

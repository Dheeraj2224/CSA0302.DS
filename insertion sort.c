#include <stdio.h>
#define MAX_SIZE 100
int arr[MAX_SIZE];
int size = 0;
void insert(int element) {
    if (size == MAX_SIZE) {
        printf("Array is full, insertion not possible\n");
    } else {
        arr[size] = element;
        size++;
    }
}
void insertionSort() {
    int i, j, key;
    for (i = 1; i < size; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
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
    insertionSort();
    printf("After sorting: \n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

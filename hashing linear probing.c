#include <stdio.h>
#define TABLE_SIZE 10
int table[TABLE_SIZE];
void init() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        table[i] = -1;
    }
}
int hash(int key) {
    return key % TABLE_SIZE;
}
void insert(int key) {
    int index = hash(key);
    while (table[index] != -1) {
        index = (index + 1) % TABLE_SIZE;
    }
    table[index] = key;
}
int search(int key) {
    int index = hash(key);
    int count = 0;
    while (count < TABLE_SIZE) {
        if (table[index] == key) {
            return index;
        }
        index = (index + 1) % TABLE_SIZE;
        count++;
    }
    return -1;
}
int main() {
    init();
    insert(10);
    insert(20);
    insert(30);

    int key = 20;
    int index = search(key);
    if (index == -1) {
        printf("%d not found in the hash table\n", key);
    } else {
        printf("%d found at index %d\n", key, index);
    }
    return 0;
}

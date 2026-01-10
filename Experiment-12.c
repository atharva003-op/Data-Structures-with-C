#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

typedef struct {
    int key;
    int flag; 
} HashTableEntry;

HashTableEntry HT[TABLE_SIZE];

void initializeHashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        HT[i].flag = 0; 
    }
}

int hashFunction(int key) {
    return key % TABLE_SIZE;
}

void insert(int key) {
    int index = hashFunction(key);
    int originalIndex = index;
    while (HT[index].flag == 1) {
        index = (index + 1) % TABLE_SIZE;
        if (index == originalIndex) { 
            printf("Hash table is full. Cannot insert key: %d\n", key);
            return;
        }
    }
    HT[index].key = key;
    HT[index].flag = 1;
    printf("Inserted key: %d at index: %d\n", key, index);
}

int search(int key) {
    int index = hashFunction(key);
    int originalIndex = index;
    while (HT[index].flag != 0) {
        if (HT[index].key == key) {
            return index; 
        }
        index = (index + 1) % TABLE_SIZE;
        if (index == originalIndex) {
            break; 
        }
    }
    return -1; 
}

int main() {
    initializeHashTable();

    insert(10);
    insert(20);
    insert(30); 

    int key = 20;
    int searchResult = search(key);
    if (searchResult != -1) {
        printf("Key %d found at index: %d\n", key, searchResult);
    } else {
        printf("Key %d not found\n", key);
    }

    return 0;
}

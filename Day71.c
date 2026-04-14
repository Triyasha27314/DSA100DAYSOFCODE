/*Problem Statement: Implement a hash table using quadratic probing with formula:
                                  h(k, i) = (h(k) + i*i) % m                      */

#include <stdio.h>
#include <string.h>

#define SIZE 100

int hashTable[SIZE];
int m; // table size

// hash function
int hash(int key){
    return key % m;
}

// insert using quadratic probing
void insert(int key){
    int index = hash(key);

    int i = 0;

    while(hashTable[(index + i*i) % m] != -1){
        i++;
    }

    int newIndex = (index + i*i) % m;
    hashTable[newIndex] = key;
}

// search using quadratic probing
int search(int key){
    int index = hash(key);

    int i = 0;

    while(hashTable[(index + i*i) % m] != -1){
        
        int currIndex = (index + i*i) % m;

        if(hashTable[currIndex] == key)
            return 1;

        i++;
    }

    return 0;
}

int main(){

    int q;
    scanf("%d", &m);   // table size
    scanf("%d", &q);   // number of operations

    // initialize table
    for(int i = 0; i < m; i++){
        hashTable[i] = -1;
    }

    char op[10];
    int key;

    for(int i = 0; i < q; i++){
        scanf("%s %d", op, &key);

        if(strcmp(op, "INSERT") == 0){
            insert(key);
        }
        else if(strcmp(op, "SEARCH") == 0){
            if(search(key))
                printf("FOUND\n");
            else
                printf("NOT FOUND\n");
        }
    }

    return 0;
}                                  
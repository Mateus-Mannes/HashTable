// implementation from linked list at: https://github.com/Mateus-Mannes/LinkedList/blob/master/llist.c
#include "llist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// hash function
// the hash code returned here is the position of the 
// first letter of the word in the alphabet (0 index)
int hash(char * word);
// prints the hash table
void printTable(node * hashTable);
// free memory from table
void destroyTable(node * hashTable);
// add value to table
void addToTable(node * table, char * value);
// creates the table
node * createTable();
// remove value from table
void removeFromTable(node * table, char * value);
// return true if the value is in the table
int isInTable(node * table, char * value);

// usage example:
int main()
{
    node * hashTable = createTable();

    addToTable(hashTable, "bottom");
    addToTable(hashTable, "butter");
    addToTable(hashTable, "balon");
    addToTable(hashTable, "boom");
    addToTable(hashTable, "fail");
    addToTable(hashTable, "full");
    addToTable(hashTable, "fool");
    addToTable(hashTable, "fast");

    printf("Hash Table: \n");
    printTable(hashTable);

    removeFromTable(hashTable, "fool");

    printf("\n\nHash Table after remove 'fool': \n");
    printTable(hashTable);

    printf("\n\nFind for 'fail': %d\n", isInTable(hashTable, "fail"));
    printf("Find for 'fool': %d\n", isInTable(hashTable, "fool"));

    destroyTable(hashTable);
    return 0;
}

// Implementations:

int isInTable(node * table, char * value){
    int index = hash(value);
    node list = table[index];
    if(list.next != NULL){
        find(list.next, value);
    } else {
        return 0;
    }
}

node * createTable() {
    node * hashTable = (node *) calloc( 26, sizeof(node));
    return hashTable;
}

void addToTable(node * table, char * value){
    int index = hash(value);
    if(table[index].next == NULL) {
        table[index].next = create(value);
    } else {
        table[index].next = insert(table[index].next, value);
    }
}

void removeFromTable(node * table, char * value){
    int index = hash(value);
    node list = table[index];
    if(list.next != NULL){
        delete(list.next, value);
    }
}

int hash(char * word) {
    char firstLetter = word[0];
    return firstLetter - 97;
}

void printTable(node * hashTable){
    for(int i = 0; i < 26; i++){
        printf("%c - ", 97 + i);
        print(hashTable[i].next);
    }
}

void destroyTable(node * hashTable) {
    for(int i = 0; i < 26; i++){
        if(hashTable[i].next != NULL){
            destroy(hashTable[i].next);
        }
    }
    free(hashTable);
}
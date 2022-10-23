#include <stdio.h>
#include <stdlib.h>
#include "llist.h"
#include <string.h>

// liked list implementation:

node * create(char * value) {
    node * newNode = (node *) malloc(sizeof(node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

void print(node * head) {
    if(head == NULL) {
        printf("\n");
        return;
    }
    
    node * ptr = head;
    do {
      printf("%s ", ptr->value);
      ptr = ptr->next;
    } while (ptr != NULL);
    printf("\n");
    return;
}

int find(node * head, char * value) {
  node * ptr = head;
  do {
      if(strcmp(ptr->value, value)  == 0){
          return 1;
      }
      ptr = ptr->next;
  } while (ptr != NULL);
  return 0;
};

node * insert(node * head, char * value) {
    node * newHead = (node *) malloc(sizeof(node));
    newHead->value = value;
    newHead->next = head;
    return newHead;
}

void destroy(node * head) {
    if(head->next != NULL){
        destroy(head->next);
    }
    free(head);
}

node * delete(node * head, char * value) {
    node * ptr = head;
    node * prevNode = NULL;
    node * newHead = head;
    do {
        int deletion = 0;    
      if(strcmp(ptr->value, value) == 0){
          deletion = 1;
          node * toDelete = ptr;
          ptr = ptr->next;
          free(toDelete);
          if(prevNode == NULL){
              newHead = ptr;
          }else{
              prevNode->next = ptr;
          }
      }
      if(!deletion){
          prevNode = ptr;
          ptr = ptr->next;
      }
    } while (ptr != NULL);
  return newHead;
}

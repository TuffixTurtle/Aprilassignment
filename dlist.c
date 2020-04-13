//
//  slist.h
//  slist
//
//  Created by William McCarthy on 084//20.
//  Copyright © 2020 William McCarthy. All rights reserved.
//

#ifndef slist_h
#define slist_h


#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct snode snode;
struct snode {
  int data;
  snode* next;
};

typedef struct slist slist;
struct slist {
  snode* head;
  snode* tail;
  size_t size;
};

snode* snode_create(int data, snode* next);
slist* slist_create(void);

bool slist_empty(slist* list);
size_t slist_size(slist* list);

void slist_popfront(slist* list);
void slist_popback(slist* list);

void slist_pushfront(slist* list, int data);
void slist_pushback(slist* list, int data);

void slist_clear(slist* list);

void slist_print(slist* list, const char* msg);

int slist_front(slist* list);
int slist_back(slist* list);

void slist_test(void);




snode* snode_create(int data, snode* next){
  snode* p = (snode*)malloc(sizeof(snode));
  p->data = data;
  p->next = next;

  return p;
}

slist* slist_create(){
  slist* p = (slist*)malloc(sizeof(slist));
  p->head = NULL;
  p->tail = NULL;
  p->size = 0;

  return p;
}

bool slist_empty (slist* list){return list->size==0;}
size_t slist_size(slist* list){return list->size;}

void checkempty(slist* list){
  if (slist_empty(list)) {fprintf(stderr, "list is empty\n"); exit(1);}
}

const char* yesorno (bool condition) {return condition ? "YES" : "no"; }

void slist_popfront (slist* list){
  checkempty (list);
  snode*p = list->head;
  list->head = list->head->next;
  free(p);
  --list->size;
}
void slist_popback (slist* list){
  if (slist_size(list) == 1) {slist_popfront(list); return;}

  snode* p = list->head;
  while (p->next != list->tail) {p = p->next;}
  p->next = NULL;
  free(list->tail);
  list->tail = p;
  --list->size;
}
void slist_pushfront (slist* list, int data){

snode* p = snode_create(data, list->head);
list->head = p;
if (list->size == 0) { list ->tail = p;}
++list->size;
}


void slist_pushback (slist* list, int data){
  if (list->size == 0) {slist_pushfront (list, data); return;}

  snode* p =snode_create (data, NULL);
  list->tail->next=p;
  list->tail=p;
  ++list->size;

}



void slist_clear (slist* list){
  while (slist_empty(list)) {
    slist_popfront(list);
  }
}

void slist_print (slist* list, const char* msg){
  printf ("%s\n", msg);
  if (slist_empty(list)) {printf("List is empty\n"); return;}

  snode* p = list->head;
  while (p != NULL){
    printf("%d --> %p\n", p ->data, p-> next);
    p = p -> next;

  }
}



int slist_front (slist* list){
  checkempty(list);
  return list->head->data;
}

int slist_back (slist* list){
  checkempty (list);
  return list->tail->data;
}

void slist_test(){
  slist* list = slist_create();
  for (int i = 10; i < 50; i += 10){
    slist_pushfront(list, i);
  }
  slist_print (list, "list is created and is....");
  printf("list size is: %zu\n", slist_size(list));
  printf("list os empty? %s\n", yesorno(slist_empty(list)));

  slist_clear(list);
  printf ("after clearing the list, is the list is now empty? %s\n", yesorno(slist_empty(list)));


free(list);
}




#endif /* slist_h */

Majority of code is cobyrighted to professor.

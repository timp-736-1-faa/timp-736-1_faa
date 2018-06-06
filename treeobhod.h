#define MALLOC(a , b) a* b = malloc(sizeof(a)); \
                      if(b ==NULL) exit(1);


#include <stdbool.h>
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct ElementOfTree{
        struct ElementOfTree* right;
        struct ElementOfTree* left;
        int key;
        int value;
        } eot;

typedef struct RootOfTree{
        struct ElementOfTree* root;
        } rot;

typedef struct queue{
        struct queue* next;
        struct queue* prev;
        struct ElementOfTree* elemtree;
        } q;

typedef struct HeadAndTail{
        struct queue* head;
        struct queue* tail;
        int size;
        } ht;

ht* CreateQueue();

void DestroyList(ht** );

void Write(ht* , eot*);

bool IsEmpty(ht* );

eot* Read(ht* );

void DeleteElem(ht* );

void ShowList(ht* );

rot* CreateTree();

void AddElementOfTree(rot* , int , int);

void FindElement(rot* , int);





#include <stdbool.h>
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct queue{
        struct queue* next;
        struct queue* prev;
        int value;
        } q;

typedef struct HeadAndTail{
	struct queue* head;
	struct queue* tail;
	int size;
	} ht;

 
ht* CreateQueue(){
        ht* creation = malloc(sizeof(ht));
        creation->head = creation->tail = NULL;
        creation->size = 0;
        return creation;
}

void DestroyList(ht** list){
        q* first = (*list)->head;
        q* buffer = NULL;
        while(first)
        {
                buffer = first->next;
                free(first);
                first = buffer;
        };
        free(*list);
        (*list) = NULL;
}


void Write(ht* queue , int newvalue){
	q* element = malloc(sizeof(q));
	if(queue->size == 0){
		queue->tail = queue->head = element;
		element->value = newvalue;
		element->prev = element->next = NULL;
		queue->size++;
		return;
	}
	element->prev = queue->tail;
	element->next = NULL;
	element->value = newvalue;
	queue->tail->next = element;
	queue->tail = element;
	queue->size++;
}

bool IsEmpty(ht* queue){
	return (queue == NULL  || queue->size == 0);
}

int Read(ht* queue){
	if (IsEmpty(queue)) exit(1);
	return queue->head->value;  	 
}		


void DeleteElem(ht* queue){
	if (IsEmpty(queue)) return;
	if(queue->size == 1){
		free(queue->head);
		queue->head = queue->tail = NULL;
		queue->size = 0;
		return;
	}
	queue->head = queue->head->next;
	free(queue->head->prev);
	queue->head->prev = NULL;
	queue->size--;
}

void ShowList(ht* list){
        if(IsEmpty(list)) return;
        q* first = list->head;
        while(first)
        {
                printf("%d",first->value);
                printf(" ");
                first = first->next;
        }
        printf("\n");
}

int main(){
	ht* queue = CreateQueue();
	for(int i = 0; i<10; ++i){
		Write(queue , i);
	}
	ShowList(queue);
	for(; !IsEmpty(queue);){
		printf("| %d %d" , Read(queue) , queue->size);
		DeleteElem(queue);
	}
	printf("\n");
	return 0;
}
	

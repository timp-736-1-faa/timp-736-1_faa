#include "treeobhod.h"

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


void Write(ht* queue , eot* newelem){
	q* element = malloc(sizeof(q));
	if(queue->size == 0){
		queue->tail = queue->head = element;
		element->elemtree = newelem;
		element->prev = element->next = NULL;
		queue->size++;
		return;
	}
	element->prev = queue->tail;
	element->next = NULL;
	element->elemtree = newelem;
	queue->tail->next = element;
	queue->tail = element;
	queue->size++;
}

bool IsEmpty(ht* queue){
	return (queue == NULL  || queue->size == 0);
}

eot* Read(ht* queue){
	if (IsEmpty(queue)) exit(1);
	return queue->head->elemtree;  	 
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
                printf("%d %d",first->elemtree->key , first->elemtree->value);
                printf(" ");
                first = first->next;
        }
        printf("\n");
}

	

#define NULLPOINTER(a) if(a == NULL) exit(1);
#define SOEBN(a) element* a = SearchElemByNumber(list , number); \
        if(a == NULL) return;
#define SEBV(a)	element* a = SearchElemByValue(list , newValue); \
        if(a == NULL) return; 

#include <stdbool.h>
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct elementOfList{
        int value;
        struct elementOfList* next;
        struct elementOfList* prev;
} element;

typedef struct HeadAndTail{
        int size;
	element* head;
        element* tail;
} ht;


ht* CreateList(){
        ht* creation = malloc(sizeof(ht));
        creation->head = creation->tail = NULL;
        creation->size = 0;
	return creation;
}

element* SearchElemByValue(ht* list , int needfullvalue){
	element* buff = list->head;
	while (buff)
        {
                if(buff->value == needfullvalue)
                        return buff;
                buff = buff->next;
        }
        return NULL;
}

element* SearchElemByNumber(ht* list , int number){
	if(list->size < number || number <= 0)
                return NULL;
        element* requestelement = NULL;
	if(number <= list->size / 2){
		requestelement = list->head;
        	for(int i = 1;i < number; ++i)
                	requestelement = requestelement->next;
		return requestelement;
	}
	else{
		requestelement = list->tail;
		for(int i = list->size;i > number; --i)
			requestelement = requestelement->prev;
		return requestelement;
	}	
}

void DestroyList(ht** list){
        element* first = (*list)->head;
        element* buffer = NULL;
        while(first)
        {
                buffer = first->next;
                free(first);
                first = buffer;
        };
        free(*list);
	(*list) = NULL;
}

bool ListIsEmpty(ht* list){
        if(list == NULL || list->size == 0)
                return true;
        else
                return false;
}

void InsertAfter(ht* list , int number , int newValue){
	SOEBN(requestElement)
	element* newElement = malloc(sizeof(element));
	NULLPOINTER(newElement)
	if(requestElement->next != NULL)
        	requestElement->next->prev = newElement;
	if(requestElement == list->tail)
                list->tail = newElement;
	newElement->value = newValue;
        newElement->next = requestElement->next;
	newElement->prev = requestElement;
	requestElement->next = newElement;
	list->size++; 
}

void InsertBefore(ht* list , int number , int newValue){
        SOEBN(requestElement)
        element* newElement = malloc(sizeof(element));
	NULLPOINTER(newElement)
        if(list->head == requestElement)
		list->head = newElement;
	if(requestElement->prev != NULL)
		requestElement->prev->next = newElement;
	newElement->prev = requestElement->prev;
	requestElement->prev = newElement;
	newElement->value = newValue;
        newElement->next = requestElement;
	list->size++;
}

void DeleteElemByNumber(ht* list , int number){
        SOEBN(requestElement)
	if(requestElement == list->head && requestElement == list->tail){
		list->head = list->tail = NULL;
		free(requestElement);
		list->size--;
		return;
	}
        if(requestElement == list->head){
		list->head = requestElement->next;
		free(requestElement);
		list->head->prev = NULL;
		list->size--;
		return;
	}
	else if(requestElement == list->tail){
		list->tail = requestElement->prev;
		free(requestElement);
		list->tail->next = NULL;
		list->size--;
		return;
	}
	else{
		requestElement->prev->next = requestElement->next;
        	requestElement->next->prev = requestElement->prev;
        	free(requestElement);
		list->size--;
	}
}

void DeleteElemByValue(ht* list , int newValue){
        SEBV(requestElement)
	if(requestElement == list->head && requestElement == list->tail){
		free(requestElement);
		list->head = list->tail = NULL;
		list->size--;
		return;
	}
	if(requestElement == list->head){
		list->head = requestElement->next;
		free(requestElement);
		list->head->prev = NULL;
		list->size--;
		return;
	}
	else if(requestElement == list->tail){
		list->tail = requestElement->prev;
		free(requestElement);
		list->tail->next = NULL;
		list->size--;
		return;
	}
	else{
		requestElement->next->prev = requestElement->prev;
		requestElement->prev->next = requestElement->next;
		list->size--;
		free(requestElement);
	}		
}

void ShowList(ht* list){
        NULLPOINTER(list)
	element* first = list->head;
	while(first)
        {
                printf("%d",first->value);
                printf(" ");
		first = first->next;
        }
	printf("\n");
}

void InsertInEnd(ht* list , int newValue){
	element* newElement = malloc(sizeof(element));
	NULLPOINTER(newElement)
	if(list->tail == NULL){
		list->head = list->tail = newElement;
		newElement->next = newElement->prev = NULL;
		newElement->value = newValue;
		list->size++;
		return;
	}
	else{		
		list->tail->next = newElement;
howList(ht* list){
        NULLPOINTER(list)
        element* first = list->head;
        while(first)
        {
                printf("%d",first->value);
                printf(" ");
                first = first->next;
        }
        printf("\n");
}

		newElement->value = newValue;
		list->tail = newElement;
		newElement->next = NULL;
		list->size++;
	}
}

int main(){
	int count = 0;
	int value = 0;
	ht* list = CreateList();
	scanf("%d" , &count);
	for(int i = 1;i <= count; ++i){
		scanf("%d" , &value);
	 	InsertInEnd(list , value);
	}
	ShowList(list);
	scanf("%d" , &value);
	DeleteElemByNumber(list , value);
	ShowList(list);
	scanf("%d" , &value);
	DeleteElemByValue(list , value);
	ShowList(list);
	scanf("%d" , &count);
	scanf("%d" , &value);
	InsertAfter(list , count , value);
	ShowList(list);
	scanf("%d" , &count);
	scanf("%d" , &value);
	InsertBefore(list , count , value);
	ShowList(list);
	return 0;
}

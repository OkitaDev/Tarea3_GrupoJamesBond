#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
	int size;
};

typedef List List;

int get_size(List* list){
	return list->size;
}

Node * createNode(void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

//Crea la lista
List * createList() 
{
  List * lista = malloc (sizeof(List));
	lista->head = NULL;
	lista->tail = NULL;
	lista->current = NULL;
	lista->size = 0;
	return lista;
}



Queue *CreateQueue(){
	return createList();
}

//Coloca el current en la primera posicion
void * firstList(List * list) 
{
	if(list->head == NULL) return NULL;
	
	list->current = list->head;
  	return (void *) list->current->data;
}

void* Front(Queue* P){
	return firstList(P);
}

//Coloca el current en la siguiente posicion
void * nextList(List * list) 
{
	if(list->current == NULL || list->current->next == NULL) return NULL;
	
	list->current = list->current->next;
	return (void *) list->current->data;
}

//Coloca el current al final de la lista
void * lastList(List * list) 
{
	if(list->tail == NULL) return NULL;
	
	list->current = list->tail;
  return (void *) list->current->data;
}

//Coloca el current al anterior del current
void * prevList(List * list) 
{
  	if(list->current == NULL || list->current->prev == NULL) return NULL;
	
	list->current = list->current->prev;
	return (void *) list->current->data;
}

//Coloca el nuevo nodo como cabeza
void pushFront(List * list, void * data) 
{
	Node * nodo = createNode(data);
	
	if(list->tail == NULL) 
	{
		list->tail = nodo;
		list->head = nodo;
	}
	else
	{
		nodo->next = list->head;
		nodo->prev = NULL;
		list->head->prev = nodo;
		list->head = nodo;
	}
	list->size++;
}

void pushBack(List * list, void * data) 
{
	Node * nodo = createNode(data);
  
  if(list->head == NULL)
	{
	 	list->head = nodo;
		list->tail = nodo;
	}
	else
	{
		nodo->next = NULL;
		nodo->prev = list->tail;
		list->tail->next = nodo;
		list->tail = nodo;
	}
	list->size++;
}

//5
void pushCurrent(List * list, void * data) 
{
	Node * nodo = createNode(data); 
	nodo->prev = list->current;

	if(list->current == list->tail)//esta al final
	{
		nodo->next = NULL;
		list->current->next = nodo;
		list->tail = nodo;
		list->tail->prev = list->current;
	}
	else 
	{
		if (list->current->next == list->head) //esta al inicio
		{
			nodo->next = list->head;
			list->current->next = nodo;
			list->head = nodo;
			list->head->next = list->current;
		}
		else //para cualquier posicion
		{
			//union con el nodo siguiente al current, para el nuevo nodo
			nodo->next = list->current->next;
			list->current->next->prev = nodo;

			//union con el nodo nuevo al current
			list->current->next = nodo;
		}
	}
	list->size++;
}

void * popFront(List * list) {
	const void * auxiliar = list->current->data;
	list->current = list->head;
	if(list->head == list->tail){
		list->head = NULL;
		list->tail = NULL;
	}else{
		list->current->next->prev = NULL;
		list->head = list->current->next;
	}
    return (void *) auxiliar;
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) 
{
	const void * auxiliar = list->current->data;

	if(list->current == list->head)
	{
		if(list->current->next == NULL){
			list->current = NULL;
			free(list->current);
		}else{
			list->current->next->prev = NULL;
			list->head = list->current->next;
			free(list->current);
			list->current = list->head;
		}
	}
	else
	{
		if(list->current == list->tail)
		{
			list->current->prev->next = NULL;
			list->tail = list->current->prev;
			free(list->current);
			list->current = list->tail;
		}
		else
		{
			list->current->next->prev = list->current->prev;
			list->current->prev->next = list->current->next;
		}
	}
	list->size--;

	return (void *) auxiliar;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}

void PopFrontQ(Queue* P){
	popFront(P);
}

void PushBackQ(Queue* P, void* E){
	pushBack(P,E);
}
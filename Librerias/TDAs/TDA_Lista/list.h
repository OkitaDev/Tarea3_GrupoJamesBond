#ifndef LIST_H
#define LIST_H

typedef struct List List;
typedef List Queue;

typedef struct Node Node;

Node * createNode(void * data);

List * createList(void);

void * firstList(List * list);

void * nextList(List * list);

void * lastList(List * list);

void * prevList(List * list);

void pushFront(List * list, void * data);

void pushBack(List * list, void * data);

void pushCurrent(List * list, void * data);

void * popFront(List * list);

void * popBack(List * list);

void * popCurrent(List * list);

void cleanList(List * list);

//cola
Queue *CreateQueue();
void* Front(Queue* P);
void PopFrontQ(Queue* P);
void PushBackQ(Queue* P, void* E);


#endif /* List_h */

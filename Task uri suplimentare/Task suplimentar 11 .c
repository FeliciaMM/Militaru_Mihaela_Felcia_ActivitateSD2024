#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Stiva pe un vector
typedef struct {
    int items[MAX];
    int top;
} StackVector;

void initStackVector(StackVector* s) {
    s->top = -1;
}

int isFullStackVector(StackVector* s) {
    return s->top == MAX - 1;
}

int isEmptyStackVector(StackVector* s) {
    return s->top == -1;
}

void pushStackVector(StackVector* s, int item) {
    if (isFullStackVector(s)) {
        printf("Stack is full\n");
        return;
    }
    s->items[++(s->top)] = item;
}

int popStackVector(StackVector* s) {
    if (isEmptyStackVector(s)) {
        printf("Stack is empty\n");
        return -1;
    }
    return s->items[(s->top)--];
}

int peekStackVector(StackVector* s) {
    if (isEmptyStackVector(s)) {
        printf("Stack is empty\n");
        return -1;
    }
    return s->items[s->top];
}

// Stiva pe o listă simplu înlănțuită
typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* top;
} StackList;

void initStackList(StackList* s) {
    s->top = NULL;
}

int isEmptyStackList(StackList* s) {
    return s->top == NULL;
}

void pushStackList(StackList* s, int item) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Heap overflow\n");
        return;
    }
    newNode->data = item;
    newNode->next = s->top;
    s->top = newNode;
}

int popStackList(StackList* s) {
    if (isEmptyStackList(s)) {
        printf("Stack is empty\n");
        return -1;
    }
    Node* temp = s->top;
    s->top = s->top->next;
    int popped = temp->data;
    free(temp);
    return popped;
}

int peekStackList(StackList* s) {
    if (isEmptyStackList(s)) {
        printf("Stack is empty\n");
        return -1;
    }
    return s->top->data;
}

// Stiva pe o listă dublu înlănțuită
typedef struct DNode {
    int data;
    struct DNode* next;
    struct DNode* prev;
} DNode;

typedef struct {
    DNode* top;
} StackDList;

void initStackDList(StackDList* s) {
    s->top = NULL;
}

int isEmptyStackDList(StackDList* s) {
    return s->top == NULL;
}

void pushStackDList(StackDList* s, int item) {
    DNode* newNode = (DNode*)malloc(sizeof(DNode));
    if (!newNode) {
        printf("Heap overflow\n");
        return;
    }
    newNode->data = item;
    newNode->next = s->top;
    newNode->prev = NULL;
    if (s->top != NULL)
        s->top->prev = newNode;
    s->top = newNode;
}

int popStackDList(StackDList* s) {
    if (isEmptyStackDList(s)) {
        printf("Stack is empty\n");
        return -1;
    }
    DNode* temp = s->top;
    s->top = s->top->next;
    if (s->top != NULL)
        s->top->prev = NULL;
    int popped = temp->data;
    free(temp);
    return popped;
}

int peekStackDList(StackDList* s) {
    if (isEmptyStackDList(s)) {
        printf("Stack is empty\n");
        return -1;
    }
    return s->top->data;
}

// Coada pe un vector
typedef struct {
    int items[MAX];
    int front, rear;
} QueueVector;

void initQueueVector(QueueVector* q) {
    q->front = -1;
    q->rear = -1;
}

int isFullQueueVector(QueueVector* q) {
    return q->rear == MAX - 1;
}

int isEmptyQueueVector(QueueVector* q) {
    return q->front == -1 || q->front > q->rear;
}

void enqueueQueueVector(QueueVector* q, int item) {
    if (isFullQueueVector(q)) {
        printf("Queue is full\n");
        return;
    }
    if (isEmptyQueueVector(q)) {
        q->front = 0;
    }
    q->items[++(q->rear)] = item;
}

int dequeueQueueVector(QueueVector* q) {
    if (isEmptyQueueVector(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    return q->items[(q->front)++];
}

int peekQueueVector(QueueVector* q) {
    if (isEmptyQueueVector(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    return q->items[q->front];
}

// Coada pe o listă simplu înlănțuită
typedef struct QNode {
    int data;
    struct QNode* next;
} QNode;

typedef struct {
    QNode* front;
    QNode* rear;
} QueueList;

void initQueueList(QueueList* q) {
    q->front = NULL;
    q->rear = NULL;
}

int isEmptyQueueList(QueueList* q) {
    return q->front == NULL;
}

void enqueueQueueList(QueueList* q, int item) {
    QNode* newNode = (QNode*)malloc(sizeof(QNode));
    if (!newNode) {
        printf("Heap overflow\n");
        return;
    }
    newNode->data = item;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}

int dequeueQueueList(QueueList* q) {
    if (isEmptyQueueList(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    QNode* temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    int item = temp->data;
    free(temp);
    return item;
}

int peekQueueList(QueueList* q) {
    if (isEmptyQueueList(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    return q->front->data;
}

// Coada pe o listă dublu înlănțuită
typedef struct DQNode {
    int data;
    struct DQNode* next;
    struct DQNode* prev;
} DQNode;

typedef struct {
    DQNode* front;
    DQNode* rear;
} QueueDList;

void initQueueDList(QueueDList* q) {
    q->front = NULL;
    q->rear = NULL;
}

int isEmptyQueueDList(QueueDList* q) {
    return q->front == NULL;
}

void enqueueQueueDList(QueueDList* q, int item) {
    DQNode* newNode = (DQNode*)malloc(sizeof(DQNode));
    if (!newNode) {
        printf("Heap overflow\n");
        return;
    }
    newNode->data = item;
    newNode->next = NULL;
    newNode->prev = q->rear;
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}

int dequeueQueueDList(QueueDList* q) {
    if (isEmptyQueueDList(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    DQNode* temp = q->front;
    q->front = q->front->next;
    if (q->front != NULL)
        q->front->prev = NULL;
    else
        q->rear = NULL;
    int item = temp->data;
    free(temp);
    return item;
}

int peekQueueDList(QueueDList* q) {
    if (isEmptyQueueDList(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    return q->front->data;
}

int main() {
    StackVector sv;
    initStackVector(&sv);
    pushStackVector(&sv, 10);
    pushStackVector(&sv, 20);
    printf("StackVector Top: %d\n", peekStackVector(&sv));
    printf

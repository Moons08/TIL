#include <stdio.h>
#include <stdlib.h>
#define INF 99999999

typedef struct {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *front;
    Node *rear;
    int count;
} Queue;

Node *front, *rear;
Queue *queue;

void push(int data) {
    
    Node *node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    
    if (queue->count == 0) {
        queue->front = node;
    } else {
        queue->rear->next = node;
    }
    queue->rear = node;
    queue->count++;
}

int pop() {
    // 큐에 남은게 없으면 프린트
    if (queue->count==0) {
        printf("queue underflow\n");
        return -INF;
    }

    Node *node = (Node*) malloc(sizeof(Node));
    node = queue->front;
    
    int data = node->data;
    queue->front = node->next;
    queue->count--;

    printf("pop! %d\n", data);
    free(node);
    return data;
}

void show() {
    Node *cur = queue->front;
    printf("-- front --\n");
    while (cur != NULL) {
        printf("%d\n", cur->data);
        cur = cur->next;
    }
    printf("-- rear --\n\n");
}

int main(void) {
    front = (Node*) malloc(sizeof(Node));
    rear = (Node*) malloc(sizeof(Node));
    queue = (Queue*) malloc(sizeof(Queue));
    queue->count = 0;
    front->next = NULL;
    rear->next = NULL;
    
    push(3);
    push(4);
    show();
    
    pop();
    pop();
    pop();
    push(2);
    push(1);
    show();
    return 0;
}

/*
-- front --
3
4
-- rear --

pop! 3
pop! 4
queue underflow
-- front --
2
1
-- rear --
*/
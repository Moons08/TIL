#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *top;
} Stack;

Node *bottom;
Stack *stack;

void push(int data) {
    Node *node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->next = stack->top;
    stack->top = node;
}

void pop() {
    Node *top = stack->top;
    if (top != bottom){
        stack->top = top->next;
        free(top);
    } else {
        printf("nothing to pop. \n");
    }
}

void show(Stack *stack) {
    Node *cur = stack->top;
    while (cur != bottom) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

int main(void) {
    bottom = (Node*)malloc(sizeof(Node));
    stack = (Stack*)malloc(sizeof(Stack));

    bottom->next = bottom;
    stack->top = bottom;
    
    push(3);
    push(2);
    push(4);
    show(stack);
    
    pop();
    show(stack);
    pop();
    show(stack);
    pop();
    pop();

    return 0;
}

/*
4 2 3 
2 3 
3 
nothing to pop. 
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data;
    struct Node *next;
} Node;

Node *head; // 구조체를 pointer 변수로

void addFront(Node *root, int data) {
    // 앞노드 = head 노드
    Node *node = (Node*)malloc(sizeof(Node)); // 노드 메모리 할당 & casting
    node->data = data; // 새노드 데이터 입력
    node->next = root->next; // 새노드 next에 앞 노드의 next(뒷 노드) 연결
    root->next = node;  // 앞 노드의 next에 새 노드 연결
}

void removeFront(Node *root) {
    // front = 지울 노드
    Node *front = root->next; 
    root->next = front->next; 
    free(front);
}

void freeAll(Node *root) {
    // 헤드 다음꺼부터 들고옴
    Node *cur = root->next;
    while (cur != NULL) {
        Node *next = cur->next;
        free(cur);
        cur = next;
    }
}

void showAll(Node *root) {
    Node *cur = root->next;
    while (cur != NULL) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
}

int main(void) {
    head = (Node*)malloc(sizeof(Node));
    head->next = NULL; // 처음과 끝 연결

    addFront(head, 2);
    addFront(head, 1);
    addFront(head, 6);
    removeFront(head);
    showAll(head);
    freeAll(head);
       
    return 0;
}

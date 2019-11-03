#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

Node *head, *tail;

/* insert 순서
    1. 앞 노드의 next를 입력 노드에 연결
    2. 입력 노드 next를 앞 노드에 연결
    3. 뒷 노드의 prev를 입력 노드에 연결
    4. 입력 노드의 next를 뒷 노드에 연결
*/

void insert(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    Node* cur;

    cur = head->next; // 헤드부터 출발
    while (cur->data < data && cur != tail) { // 오름차순으로 정렬
        // 입력 노드 들어갈 자리 찾기
        cur = cur->next;
    };
    // 현재 위치(뒷 노드)의 앞 노드 주소값 포인터 생성
    Node* prev = cur->prev;

    // 1. 앞 노드의 next에 입력 노드 연결
    prev->next = node;

    // 2. 입력 노드의 prev를 앞 노드에 연결
    node->prev = prev;
    
    // 3. 뒷 뒷노드의 prev를 입력 노드에 연결
    cur->prev = node;

    // 4. 입력 노드의 next를 뒷 노드에 연결
    node->next = cur;
}

void removeFront() {
    // 가장 앞(헤드 바로 뒤) 노드 포인터
    Node* node = head->next;
    if (node->next) {
        // head를 지울 노드의 다음 노드에 연결
        head->next = node->next;
        
        // 뒷 노드 (가장 앞으로 올 노드) 포인터
        Node* next = node->next;
        // head에 연결
        next->prev = head;
        // 지울 노드 메모리 해제
        free(node);
    } else {
        printf("nothing to remove.\n");
    }
}

void show() {
    Node* cur = head->next;
    if (cur->next) {
        while (cur != tail) {
            printf("%d ", cur->data);
            cur = cur->next;
        };
        printf("\n");
    } else {
        printf("nothing to show.\n");
    }
}

int main(void) {
    head = (Node*)malloc(sizeof(Node));
    tail = (Node*)malloc(sizeof(Node));
    
    head->next = tail;
    head->prev = NULL;

    tail->next = NULL;
    tail->prev = head;

    show();
    insert(2);
    insert(3);
    show();

    removeFront();
    show();
    removeFront();
    removeFront();

    return 0;
}

/*
nothing to show.
2 3 
3 
nothing to remove.
*/

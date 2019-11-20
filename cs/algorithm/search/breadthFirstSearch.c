#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1001
#define INF 99999999

/**
 * 1 탐색 시작 노드를 큐에 삽입
 * 2 큐에서 노드를 꺼내 인접 노드 중 미방문 노드를 모두 큐에 삽입 후 방문 처리
 * 3 2번을 반복
*/

typedef struct {
    int index;
    struct Node *next;
} Node;

typedef struct {
    Node *front;
    Node *rear;
    int count;
} Queue;


Node** a;
int n, m, c[MAX_SIZE];

void addFront(Node *root, int index) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->index = index;
    node->next = root->next;
    root->next = node;
}

void queuePush(Queue *queue, int index) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->index = index;
    node->next = NULL;
    if (queue->count == 0) {
        queue->front = node; // 큐에 하나도 없으면 프론트 연결
    } else {
        queue->rear->next = node; // 아니면 뒤에 차곡차곡
    }
    queue->rear = node; // 새로운 꼬다리 탄생
    queue->count++;
}

int queuePop (Queue *queue) {
    if (queue->count == 0) {
        printf("queue underflow.\n");
        return -INF;
    }
    Node *node = queue->front;
    int index = node->index;
    queue->front = node->next;
    free(node);
    queue->count--;
    return index;
}

void bfs(int start) {
    Queue q;
    q.front = q.rear = NULL;
    q.count = 0;
    queuePush(&q, start);
    c[start] = 1;
    while (q.count != 0) {
        int x = queuePop(&q);
        printf("%d ", x); // 큐에 있는 애를 꺼내서 표시
        Node *cur = a[x]->next; // 연결된 다음 놈으로
        while (cur != NULL) {
            int next = cur->index; 
            // 현재 노드의 값=다음 연결 노드
            if (!c[next]) { // 미방문 노드일 경우
                queuePush(&q, next); // 큐에 넣고
                c[next] = 1; // 방문 표시
            }
            cur = cur->next; //방문 노드면 그 노드로 커서 옮겨서 반복
        }
    }
}

int main(void) {
    scanf("%d %d", &n, &m);
    a = (Node**)malloc(sizeof(Node*) * (MAX_SIZE));
    for (int i = 0; i < n; i++)
    {
        a[i] = (Node*)malloc(sizeof(Node));
        a[i]->next = NULL;
    }
    for (int i = 0; i < m; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        addFront(a[x], y);
        addFront(a[y], x);
    }
    bfs(1);

    return 0;    
}
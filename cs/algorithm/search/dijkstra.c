#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define NODE_MAX 20001
#define EDGE_MAX 600001

typedef struct {
    int cost;
    int node;
} Edge;

typedef struct {
    Edge *heap[EDGE_MAX];
    int count;
} priorityQueue;

void swap(Edge *a, Edge *b) {
    Edge tmp;
    tmp.cost = a->cost;
    tmp.node = a->node;
    a->cost = b->cost;
    a->node = b->node;
    b->cost = tmp.cost;
    b->node = tmp.node;
}

void push(priorityQueue *pq, Edge *edge) {
    if (pq->count >= EDGE_MAX) return;
    pq->heap[pq->count] = edge;
    int now = pq->count;
    int parent = (pq->count - 1) / 2;
    // 트리는 min heap으로 구성
    while (now > 0 && pq->heap[now]->cost < pq->heap[parent]->cost) {
        swap(pq->heap[now], pq->heap[parent]);
        now = parent;
        parent = (parent - 1) / 2;
    }
    pq->count++;
}

Edge *pop(priorityQueue *pq) {
    if (pq->count <= 0) return NULL;
    Edge *res = pq->heap[0];
    pq->count--;
    pq->heap[0] = pq->heap[pq->count]; // 끝에 놈을 최상단으로
    int now = 0, leftChild = 1, rightChild = 2;
    int target = now;
    // 하향식으로 힙구성
    while (leftChild < pq->count) {
        if (pq->heap[target]->cost > pq->heap[leftChild]->cost) target = leftChild;
        if (pq->heap[target]->cost > pq->heap[rightChild]->cost 
            && rightChild < pq->count) target = rightChild;
        if (target == now) break;
        else {
            swap(pq->heap[now], pq->heap[target]);
            now = target;
            leftChild = now * 2 + 1;
            rightChild = now * 2 + 2;
        }
    }
    return res;
}

typedef struct {
    Edge *data;
    struct Node *next;
} Node;

Node **adj;
int ans[NODE_MAX];

void addNode(Node **target, int index, Edge *edge) {
    if (target[index] == NULL) {
        target[index] = (Node*)malloc(sizeof(Node));
        target[index]->data = edge;
        target[index]->next = NULL;
    }
    else {
        Node *node = (Node*)malloc(sizeof(Node));
        node->data = edge;
        node->next = target[index];
        target[index] = node;
    }
}

int main(void) {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    adj = (Node**)malloc(sizeof(Node*) * (n + 1));
    for (int i = 0; i <= n; i++) {
        adj[i] = NULL;
        ans[i] = INT_MAX; // 초기화
    }
    priorityQueue *pq;
    pq = (priorityQueue*)malloc(sizeof(priorityQueue));
    pq->count = 0;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        Edge *edge = (Edge*)malloc(sizeof(Edge));
        edge->node = b;
        edge->cost = c;
        addNode(adj, a, edge);
    }
    // algorithms

    /** 
     * 1. 그래프 시작점을 트리 T에 포함
     * 2. T에 포함된 노드 - 포함X 노드 간의 간선 중 이동거리가 가장 작은 간선 탐색
     * 3. 포함X노드를 트리 T에 포함
     * 2-3 반복
     */

    ans[k] = 0;
    Edge *start = (Edge*)malloc(sizeof(Edge));
    start->cost = 0; start->node = k; push(pq, start); // 1
    while (1) {
        Edge *now = pop(pq); 
        if (now == NULL) break;
        int curNode = now->node;
        int curCost = now->cost;
        if (ans[curNode] < curCost) continue;
        Node *cur = adj[curNode];

        while (cur != NULL) {
            Edge *tmp = cur->data;
            tmp->cost += curCost;
            if (tmp->cost < ans[tmp->node]) { // 2
                ans[tmp->node] = tmp->cost;
                push(pq, tmp); // 3
                cur = cur->next;
            }
        }
    }   
    for (int i = 0; i <= n; i++) {
        if (ans[i] == INT_MAX) printf("INF\n");
        else printf("%d\n", ans[i]);
    }
}
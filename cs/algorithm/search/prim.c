#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define NODE_MAX 1001
#define EDGE_MAX 200001


/**
 * 1. 그래프에서 하나의 꼭짓점을 선택하여 트리 T를 만든다.
 * 2. T에 포함된 노드와 포함되지 않은 노드 사이 간선 중 가장 작은 값을 찾는다.
 * 3. 간선에 연결된 T에 포함되지 않은 노드를 트리 T에 포함시킨다.
 * 2-3 반복
 */

typedef struct {
    int cost;
    int node;
} Edge;

void swap(Edge *a, Edge *b) {
    Edge tmp;
    tmp.cost = a->cost;
    tmp.node = a->node;
    a->cost = b->cost;
    a->node = b->node;
    b->cost = tmp.cost;
    b->node = tmp.node;
}

typedef struct {
    Edge *heap[EDGE_MAX];
    int count;
} priorityQueue;

void push(priorityQueue *pq, Edge *edge) {
    if (pq->count >= EDGE_MAX) return;
    pq->heap[pq->count] = edge; // 우선순위 큐 count 위치에 edge 입력
    int now = pq->count; // 입력 후 count 
    int parent = (pq->count -1) / 2; // 부모노드 위치
    // 상향식 힙구성 -> cost 낮은 애가 가장 위로 가도록
    while (now > 0 && pq->heap[now]->cost < pq->heap[parent]->cost) {
        swap(pq->heap[now], pq->heap[parent]);
        now = parent;
        parent = (parent - 1) / 2;
    }
    pq->count++;
}

Edge *pop(priorityQueue *pq) {
    if (pq->count <= 0) return NULL;
    Edge *res = pq->heap[0]; // 최상단 노드(최소비용엣지) 추출
    pq->count--;
    pq->heap[0] = pq->heap[pq->count];
    int now = 0, leftChild = 1, rightChild = 2;
    int target = now;

    while (leftChild < pq->count) {
        // cost 낮은 놈이 타겟
        if (pq->heap[target]->cost > pq->heap[leftChild]->cost ) target = leftChild;
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

typedef struct Node {
    Edge *data;
    struct Node *next;
} Node;

Node **adj;
int d[NODE_MAX];

void addNode(Node **target, int index, Edge *edge) {
    if (target[index] == NULL) {
        target[index] = (Node*)malloc(sizeof(Node));
        target[index]->data = edge;
        target[index]->next = NULL;
    } else {
        // 연결리스트의 인덱스가 빈 경우, 가장 앞에 노드를 생성하여 연걸
        Node *node = (Node*)malloc(sizeof(Node));
        node->data = edge;
        node->next = target[index];
        target[index] = node;
    }
}

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    adj = (Node**)malloc(sizeof(Node*) * (n + 1));
    for (int i = 0; i <= n; i++) {
        adj[i] = NULL;
    }
    priorityQueue *pq;
    pq = (priorityQueue*)malloc(sizeof(priorityQueue));
    pq->count = 0;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        // a, b 양방향에서 c 비용 엣지를 연결
        Edge *edge1 = (Edge*)malloc(sizeof(Edge));
        edge1->node = b;
        edge1->cost = c;
        addNode(adj, a, edge1);
        Edge *edge2 = (Edge*)malloc(sizeof(Edge));
        edge2->node = a;
        edge2->cost = c;
        addNode(adj, b, edge2);
    }

    long long res = 0;
    Edge *start = (Edge*)malloc(sizeof(Edge));
    start->cost = 0; start->node = 1; push(pq, start); // 1번노드부터 시작, 최초세팅
    for (int i = 0; i <= n; i++)
    {
        int nextNode = -1, nextCost = INT_MAX;
        while (1) {
            Edge *now = pop(pq); // pq 최상단 노드 하나 뽑음 (비용 최소 노드일 것임)
            if (now == NULL) break;
            nextNode = now->node; // 엣지에 연결된 노드 
            if (!d[nextNode]) { // 방문하지 않은 노드에 대해 비용 업뎃
                nextCost = now->cost; break;
            }
        }
        if (nextCost == INT_MAX) printf("연결 그래프가 아닙니다.\n");
        res += nextCost; 
        d[nextNode] = 1; // 들렀다는 표시
        Node *cur = adj[nextNode]; // 그래프에서 이 노드의 위치 반환
        while (cur != NULL) { 
            push(pq, cur->data); // pq에 밀어넣음 -> 코스트 낮은 애가 최상단으로
            cur = cur->next; // 더이상 연결된 노드가 없을 때까지 반복
            } 
    }
    printf("%lld\n", res);
}


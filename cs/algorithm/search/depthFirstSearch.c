#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1001

/**
 * 1 탐색 시작 노드를 스택에 삽입
 * 2 스택 최상단 노드의 인접노드가 있으면 그 노드 스택 삽입
 * 3 인접 노드가 없으면 스택에서 최상단 노드 추출
 * 2-3 반복
*/

typedef struct {
    int index;
    struct Node *next;
} Node;

Node** a;
int n, m, c[MAX_SIZE];

void addFront(Node *root, int index) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->index = index;
    node->next = root->next;
    root->next = node;
}

void dfs(int x) {
    if (c[x]) return; // 방문한 적이 있다면 바로 리턴
    c[x] = 1; // 방문했다고 표시
    printf("%d", x);
    Node *cur = a[x]->next; // 연결되어있는 노드로 커서 옮김
    while (cur != NULL) { // 재귀
        int next = cur->index;
        dfs(next); 
        cur = cur->next;
    }
}

int main(void) {
    scanf("%d %d", &n, &m);
    a = (Node**)malloc(sizeof(Node*) * (MAX_SIZE));
    for (int i = 0; i <= n; i++)
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
    dfs(1);

    return 0;    
}
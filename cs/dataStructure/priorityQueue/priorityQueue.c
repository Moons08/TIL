#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10000

typedef struct {
    int heap[MAX_SIZE];
    int count;
} priorityQueue;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void push(priorityQueue *pq, int data) {
    if (pq->count >= MAX_SIZE) return;
    pq->heap[pq->count] = data; // heap list의 count 위치에(마지막 위치) 입력
    int now = pq->count; // 방금 삽입한 노드를 포함한 총 노드 개수
    int parent = (pq->count - 1) / 2; // 방금 삽입한 노드의 부모 노드 위치

    while (now > 0 && pq->heap[now] > pq->heap[parent]) {
        // 부모보다 크면 자리를 바꾸며 상향 이동, 루트 노드까지
        swap(&pq->heap[now], &pq->heap[parent]);
        now = parent;
        parent = (parent - 1) / 2;
    }
    pq->count++; 
}

int pop(priorityQueue *pq) {
    if (pq->count <= 0) return -9999;
    int res = pq->heap[0]; // 루트 노드 꺼내가면 됨
    pq->count--;
    // 가장 마지막 노드를 루트에 갖다 놓고 하향 이동
    pq->heap[0] = pq->heap[pq->count];
    int now = 0, leftChild = 1, rightChild = 2;
    int target = now;

    while (leftChild < pq->count) {
        // 왼쪽 우선하여 더 큰 노드(target)와 자리 교체
        if (pq->heap[target] < pq->heap[leftChild]) target = leftChild;
        if (pq->heap[target] < pq->heap[rightChild] && rightChild < pq->count) target = rightChild;
        if (target == now) break;
        else {
            swap(&pq->heap[now], &pq->heap[target]);
            now = target;
            leftChild = now * 2 + 1;
            rightChild = now * 2 + 2;
        }   
    }
    return res;
}

int main(void) {
    int n, data;
    scanf("%d", &n);
    priorityQueue pq;
    pq.count = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        push(&pq, data);
    }
    for (int i = 0; i < n; i++) {
        int data = pop(&pq);
        printf("%d ", data);
    }
    return 0;
}
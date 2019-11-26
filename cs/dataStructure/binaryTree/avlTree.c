#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data;
    int height;
    struct Node *leftChild;
    struct Node *rightChild;
} Node;

int getMax(int a, int b) {
    if (a > b) return a;
    return b;
}

int getHight(Node *node) {
    if (node == NULL) return 0;
    return node->height;
}

void setHeight(Node *node) {
    node->height = getMax(getHight(node->leftChild), getHight(node->rightChild)) + 1;
}

int getDifference(Node *node) {
    if (node == NULL) return 0;
    Node *leftChild = node->leftChild;
    Node *rightChild = node->rightChild;
    return getHight(leftChild) - getHight(rightChild);
}

/** 균형이 깨지는 경우
 * LL: X의 왼쪽 자식의 왼쪽에 삽입
 * LR: X의 왼쪽 자식의 오른쪽 삽입
 * RR: X 오른쪽 오른쪽에 삽입
 * RL: X 오른쪽 왼쪽에 삽입
 */

Node *rotateLL(Node *node) {
    Node *leftChild = node->leftChild; // P(부모)의 L
    node->leftChild = leftChild->rightChild; // L의 R(손자)을 P의 L(자식)로 옮김
    leftChild->rightChild = node; // L(자식)의 R(손자)을 P
    // L 자식 밑에 있던  R 손자가 P 부모의 L 자식 위치로
    // P 부모가 L의 R 자식 위치로
    setHeight(node);
    return leftChild;
}

Node *rotateRR(Node *node) {
    Node *rightChild = node->rightChild; // P's R
    node->rightChild = rightChild->leftChild;// P's R <- P's R's L
    rightChild->leftChild = node; // P's L <- P
    // P's L -> P , P's R's L -> P's R
    setHeight(node);
    return rightChild; // new P
}

Node *rotateLR(Node *node) {
    Node *leftChild = node->leftChild;
    node->leftChild = rotateRR(leftChild);
    return rotateLL(node);
}

Node *rotateRL(Node *node) {
    Node *rightChild = node->rightChild;
    node->rightChild = rotateLL(rightChild);
    return rotateRR(node);
}

Node *balance(Node *node) {
    int diff = getDifference(node);
    if (diff >= 2) { // L 치우침
        if (getDifference(node->leftChild) >= 1) { // LL 치우침
            node = rotateLL(node);
        } else { // LR 치우침
            node = rotateLR(node);
        }
    } else if (diff <= -2) {
        if (getDifference(node->rightChild) <= -1) {
            node = rotateRR(node);
        } else {
            node = rotateRL(node);
        }
    }
    setHeight(node); 
    return node;
}

Node *insertNode(Node *node, int data) {
    if (!node) {
        node = (Node*)malloc(sizeof(Node));
        node->data = data;
        node->height = 1;
        node->leftChild = node-> rightChild = NULL;
    } else if (data < node->data) {
        node->leftChild = insertNode(node->leftChild, data);
        node = balance(node);
    } else if (data > node->data) {
        node->rightChild = insertNode(node->rightChild, data);
        node = balance(node);
    } else {
        printf("중복 발생\n");
    }
    return node;
}

Node *root = NULL;

void display(Node *node, int level) {
    if (node != NULL) {
        display(node->rightChild, level+1);
        printf("\n");
        if (node == root) {
            printf("Root: ");
        }
        for (int i = 0; i < level && node != root; i++)
        {
            printf("    ");
        }
        printf("%d(%d)", node->data, getHight(node));
        display(node->leftChild, level + 1);
    }
}

int main(void) {
    root = insertNode(root, 7);
    root = insertNode(root, 4);
    root = insertNode(root, 1);
    root = insertNode(root, 2);
    root = insertNode(root, 12);
    root = insertNode(root, 0);
    root = insertNode(root, 11);
    root = insertNode(root, 127);
    root = insertNode(root, 98);
    root = insertNode(root, 23);
    root = insertNode(root, 42);
    root = insertNode(root, 13);
    root = insertNode(root, 44);
    root = insertNode(root, 122);
    display(root, 1); printf("\n");
}
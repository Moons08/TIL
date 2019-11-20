#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data;
    struct Node* leftChild;
    struct Node* rightChild;
} Node;

Node* insertNode(Node* root, int data) {
    if (root == NULL) {
        root = (Node*)malloc(sizeof(Node));
        root->leftChild = root->rightChild = NULL;
        root->data = data;
    } else {
        if(root->data > data) {
            root->leftChild = insertNode(root->leftChild, data);
        } else {
            root->rightChild = insertNode(root->rightChild, data);
        }
    }
    return root;
}

Node *deleteNode(Node *root, int data) {
    Node *ndoe = NULL;
    if (root==NULL) return NULL;
    if (root->data > data) root->leftChild = deleteNode(root->leftChild, data);
    else if (root->data > data) return deleteNode(root->leftChild, data);
    else { // 삭제할 노드를 찾은 경우
        if (root->leftChild != NULL && root->rightChild != NULL) {
            node = findMinNode(root->rightChild);
            root->data = node->data; // 오른쪽에서 가장 작은 놈 값으로 루트(삭제할 놈)에 채워놓음
            root->rightChild = deleteNode(root->rightChild, node->data);
        }
        else {
            // 자식 중 하나만 있으면 그놈으로 루트 노드 대체
            node = (root->leftChild != NULL) ? root->leftChild : root->rightChild;
            free(root);
            return node;
        }
    }
    return root;    
}


Node* findMinNode(Node* root) {
    Node* node = root;
    while (node->leftChild != NULL) {
        node = node->leftChild;
    }
    return node; // 왼쪽끝으로 가면 가장 작은놈
}

Node* searchNode(Node* root, int data) {
    if (root == NULL) return NULL;
    if (root->data == data) return root;
    else if (root->data > data) return searchNode(root->leftChild, data);
    else return searchNode(root->rightChild, data);
}

void preorder(Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->leftChild);
    preorder(root->rightChild);
}

int main(void) {
    Node* root = NULL;
    root = insertNode(root, 30);
    root = insertNode(root, 17);
    root = insertNode(root, 1);
    root = insertNode(root, 20);
    root = insertNode(root, 10);
    preorder(root);
}
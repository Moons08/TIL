#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node* initNode(int data, Node* leftNode, Node* rightNode) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = leftNode;
    node->right = rightNode;
    return node;
};

void show(Node* node, char* order) {
    // 비교부분을 빼내려 해봤는데, 왜인지 변수가 초기화되질 않는다.
    // int pre, in, post;
    // if (strcmp(order, "pre")==0) {pre=1;}
    // if (strcmp(order, "in")==0) {in=1;}
    // if (strcmp(order, "post")==0) {post=1;}
   
    if (node) {
        if (strcmp(order, "pre")==0) printf("%d\n", node->data);
        show(node->left, order);
        if (strcmp(order, "in")==0) printf("%d\n", node->data);
        show(node->right, order);
        if (strcmp(order, "post")==0) printf("%d\n", node->data);
    }
}

int main(void) {

    Node* n8 = initNode(1378, NULL, NULL);
    Node* n7 = initNode(137, n8, NULL);
    Node* n6 = initNode(136, NULL, NULL);
    Node* n5 = initNode(125, NULL, NULL);
    Node* n4 = initNode(124, NULL, NULL);
    Node* n3 = initNode(13, n6, n7);
    Node* n2 = initNode(12, n4, n5);
    Node* n1 = initNode(1, n2, n3);

    printf("== pre ==\n");
    show(n1, "pre");
    printf("== in ==\n");
    show(n1, "in");
    printf("== post ==\n");
    show(n1, "post");

    return 0;
}
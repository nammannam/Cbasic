#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct node {
    char classCode[9];
    char room[7];
    struct node *left, *right;
} Node;
 
Node* newNode(char classCode[], char room[]) {
    Node* node = (Node*)malloc(sizeof(Node));
    strcpy(node->classCode, classCode);
    strcpy(node->room, room);
    node->left = node->right = NULL;
    return node;
}
 
Node* insert(Node* node, char classCode[], char room[]) {
    if (node == NULL) return newNode(classCode, room);
 
    if (strcmp(classCode, node->classCode) < 0)
        node->left = insert(node->left, classCode, room);
    else if (strcmp(classCode, node->classCode) > 0)
        node->right = insert(node->right, classCode, room);
 
    return node;
}
 
void inOrderUtil(Node* node, Node* rightmost) {
    if (node != NULL) {
        inOrderUtil(node->left, rightmost);
        printf("%s", node->classCode);
        if (node != rightmost) {
            printf(" ");
        }
        inOrderUtil(node->right, rightmost);
    }
}

void inOrder(Node* root) {
    if (root != NULL) {
        Node* rightmost = root;
        while (rightmost->right != NULL) {
            rightmost = rightmost->right;
        }
        inOrderUtil(root, rightmost);
    }
}
 
int countStep(Node* node, char classCode[]) {
    int step = 0;
    while (node != NULL) {
        step++;
        if (strcmp(classCode, node->classCode) < 0)
            node = node->left;
        else if (strcmp(classCode, node->classCode) > 0)
            node = node->right;
        else
            return step;
    }
    return step;
}
 
int main() {
    Node* root = NULL;
    char operation[10], classCode[9], room[7];
 
    while (scanf("%s", operation) != EOF && operation[0] != '#') {
        if (strcmp(operation, "insert") == 0) {
            scanf("%s %s", classCode, room);
            root = insert(root, classCode, room);
        } else if (strcmp(operation, "inOrder") == 0) {
            inOrder(root);
            printf("!\n");
        } else if (strcmp(operation, "countStep") == 0) {
            scanf("%s", classCode);
            printf("%d\n", countStep(root, classCode));
        }
    }
 
    return 0;
}
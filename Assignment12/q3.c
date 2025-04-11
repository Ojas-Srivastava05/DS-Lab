#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

int search(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

struct Node* buildTree(int inorder[], int preorder[], int inStart, int inEnd, int* preIndex) {
    if (inStart > inEnd)
        return NULL;

    int current = preorder[*preIndex];
    (*preIndex)++;

    struct Node* node = newNode(current);

    if (inStart == inEnd)
        return node;

    int inIndex = search(inorder, inStart, inEnd, current);

    node->left = buildTree(inorder, preorder, inStart, inIndex - 1, preIndex);
    node->right = buildTree(inorder, preorder, inIndex + 1, inEnd, preIndex);

    return node;
}

void postOrder(struct Node* node) {
    if (node == NULL)
        return;
    postOrder(node->left);
    postOrder(node->right);
    printf("%d ", node->data);
}

int main() {
    int inorder[] = {1, 8, 19, 13, 25, 9, 5, 10, 4, 3};
    int preorder[] = {25, 8, 1, 13, 19, 5, 9, 4, 10, 3};
    int length = sizeof(inorder) / sizeof(inorder[0]);
    int preIndex = 0;

    struct Node* root = buildTree(inorder, preorder, 0, length - 1, &preIndex);

    printf("Postorder traversal of constructed tree: ");
    postOrder(root);
    printf("\n");

    return 0;
}

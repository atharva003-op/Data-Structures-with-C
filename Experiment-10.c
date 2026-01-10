#include <stdio.h>
#include <stdlib.h>

typedef struct BSTNode {
    int data;
    struct BSTNode *left, *right;
} BST;

BST* newNode(int data) {
    BST* node = (BST*)malloc(sizeof(BST));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

BST* insert(BST* root, int data) {
    if (root == NULL)
        return newNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

void inorder(BST* root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(BST* root) {
    if (root) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(BST* root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

BST* search(BST* root, int key) {
    if (root == NULL || root->data == key)
        return root;

    if (key < root->data)
        return search(root->left, key);
    return search(root->right, key);
}

int main() {
    BST* root = NULL;
    int choice, key;
    int data[] = {6, 9, 5, 2, 8, 15, 24, 14, 7};
    int n = sizeof(data) / sizeof(data[0]);

    for (int i = 0; i < n; i++)
        root = insert(root, data[i]);

    do {
        printf("\n1.Inorder  2.Preorder  3.Postorder  4.Search  5.Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: inorder(root); break;
            case 2: preorder(root); break;
            case 3: postorder(root); break;
            case 4:
                printf("Enter key: ");
                scanf("%d", &key);
                printf(search(root, key) ? "Found\n" : "Not Found\n");
                break;
            case 5:
            printf("Exited Sucessfully!!");
            break;
            default:
            printf("Invalid choice!");
            break;
        }
    } while (choice != 5);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

struct bst {
    int val;
    struct bst *left;
    struct bst *right;
};

struct bst* insert(struct bst *root, int n) {
    if (!root) {
        root = malloc(sizeof(struct bst));
        root->val = n;
        root->left = root->right = NULL;
        return root;
    }

    if (n < root->val)
        root->left = insert(root->left, n);
    else
        root->right = insert(root->right, n);
    return root;
}

struct bst* delete(struct bst *root, int n) {
    if (!root) return NULL;

    if (n < root->val)
        root->left = delete(root->left, n);
    else if (n > root->val)
        root->right = delete(root->right, n);
    else {
        if (root->left == NULL) return root->right;
        if (root->right == NULL) return root->left;

        struct bst *temp = root->right;
        while (temp->left)
            temp = temp->left;
        root->val = temp->val;
        root->right = delete(root->right, temp->val);
    }
    return root;
}

void traverse_in(struct bst *root) {
    if (root) {
        traverse_in(root->left);
        printf("%d ", root->val);
        traverse_in(root->right);
    }
}

int main() {
    int arr[] = {14, 2, 5, 20, 42, 1, 4, 16};
    struct bst *root = NULL;
    for (int i = 0; i < 8; i++) {
        root = insert(root, arr[i]);
    }
    traverse_in(root);
    printf("\n");
    root = delete(root, 2);
    traverse_in(root);
    printf("\n");
    return 0;
}
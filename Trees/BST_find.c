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

int find(struct bst *root, int n) {
    if (!root) return 0;

    if (n == root->val) {
        return 1;
    }

    if (n < root->val)
        return find(root->left, n);
    else
        return find(root->right, n);
}

int find_min(struct bst* root) {
    if (!root) return -1;
    if (root->left == NULL)
        return root->val;
    else
        return find_min(root->left);
}

int find_max(struct bst* root) {
    if (!root) return -1;
    if (root->right == NULL)
        return root->val;
    else
        return find_max(root->right);
}

int main() {
    int arr[] = {14, 2, 5, 20, 42, 1, 4, 16};
    struct bst *root = NULL;
    for (int i = 0; i < 8; i ++) {
        root = insert(root, arr[i]);
    }

    printf("%d\n", find(root, 16));
    printf("%d\n", find(root, 15));
    printf("%d\n", find_min(root));
    printf("%d\n", find_max(root));
    return 0;
}

/*

Insert (iterative)

struct bst* insert(struct bst *root, int x) {
    struct bst *new = malloc(sizeof(struct bst));
    new->val = x;
    new->left = new->right = NULL;
    if (!root) return new;

    struct bst *node = root;
    while (1) {
        if (x < node->val) {
            if (!node->left){
                node->left = new;
                break;
            }
            node = node->left;
        } else {
            if (!node->right){
                node->right = new;
                break;
            }
            node = node->right;
        }
    }

    return root;
}

*/
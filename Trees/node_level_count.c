#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *left;
    struct node *right;
} node;

node* new_node(int val) {
    node *new = malloc(sizeof(node));
    new->val = val;
    new->left = new->right = NULL;
    return new;
}

int search(int inorder[], int start, int stop, int val) {
    for (int i = start; i <= stop; i++) {
        if (inorder[i] == val)
            return i;
    }
    return -1;
}

node* build(int inorder[], int preorder[], int start, int end, int *preindex) {
    if (start > end)
        return NULL;
    
    int c = preorder[*preindex];
    node *root = new_node(c);
    (*preindex)++;
    
    if (start == end) 
        return root;
    
    int inindex = search(inorder, start, end, c);
    root->left = build(inorder, preorder, start, inindex - 1, preindex);
    root->right = build(inorder, preorder, inindex + 1, end, preindex);
    
    return root;
}

int node_level_count(node* root, int L) {
    if (root == NULL) return 0;
    if (L == 0) return 1;
    return node_level_count(root->left, L-1) + node_level_count(root->right, L-1);
}

int main() {
    int inorder[]  = {4, 2, 5, 1, 6, 3, 7};
    int preorder[] = {1, 2, 4, 5, 3, 6, 7};
    int n = 7;
    int preindex = 0;
    node *root = build(inorder, preorder, 0, n - 1, &preindex);
    printf("%d\n", node_level_count(root, 2));
    return 0;
}
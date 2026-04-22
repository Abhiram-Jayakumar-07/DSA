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

void level_traverse(node *root){
    node* q[100];
    int front = 0, rear = 0;

    q[rear++] = root;
    while (front < rear) {
        node *curr = q[front++];
        printf("%d ", curr->val);
        if (curr->left) q[rear++] = curr->left;
        if (curr->right) q[rear++] = curr->right;
    }
}

int main() {
    int inorder[]  = {4, 2, 5, 1, 6, 3, 7};
    int preorder[] = {1, 2, 4, 5, 3, 6, 7};
    int n = 7;
    int preindex = 0;
    node *root = build(inorder, preorder, 0, n - 1, &preindex);
    level_traverse(root);
    printf("\n");
    return 0;
}
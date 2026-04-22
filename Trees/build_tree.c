// Inorder + Postorder

#include <stdio.h>
#include <stdlib.h>

struct tree {
    int val;
    struct tree *left;
    struct tree *right;
};

struct tree* new_node(int val) {
    struct tree *new = malloc(sizeof(struct tree));
    new->val = val;
    new->left = new->right = NULL;
    return new;
}

int search(int inorder[], int start, int end, int val) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == val)
            return i;
    }
    return -1;
}

struct tree* build(int inorder[], int postorder[], int start, int end, int *postindex) {
    if (start > end) return NULL;

    int c = postorder[*postindex];
    (*postindex)--;
    struct tree *root = new_node(c);

    int inindex = search(inorder, start, end, c);
    root->right = build(inorder, postorder, inindex+1, end, postindex);
    root->left = build(inorder, postorder, start, inindex-1, postindex);
    return root;
}


void in_traverse(struct tree *root){
    if (root != NULL) {
        in_traverse(root->left);
        printf("%d ", root->val);
        in_traverse(root->right);
    }
}

int main() {
    int inorder[] = {2, 1};
    int postorder[] = {2, 1};
    int n = 2;
    int postindex = n - 1;
    struct tree *root = build(inorder, postorder, 0, n - 1, &postindex);
    in_traverse(root);
    printf("\n");
    return 0;
}

/*

Inorder + Preorder

#include <stdio.h>
#include <stdlib.h>

struct tree {
    int val;
    struct tree *left;
    struct tree *right;
};

struct tree* new_node(int val) {
    struct tree *new = malloc(sizeof(struct tree));
    new->val = val;
    new->left = new->right = NULL;
    return new;
}

int search(int inorder[], int start, int end, int val) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == val)
            return i;
    }
    return -1;
}

struct tree* build(int inorder[], int preorder[], int start, int end, int *preindex) {
    if (start > end) return NULL;

    int c = preorder[*preindex];
    (*preindex)++;
    struct tree *root = new_node(c);

    int inindex = search(inorder, start, end, c);
    root->left = build(inorder, preorder, start, inindex-1, preindex);
    root->right = build(inorder, preorder, inindex+1, end, preindex);
    return root;
}


void in_traverse(struct tree *root){
    if (root != NULL) {
        in_traverse(root->left);
        printf("%d ", root->val);
        in_traverse(root->right);
    }
}

int main() {
    int inorder[] = {2, 1};
    int preorder[] = {1, 2};
    int n = 2;
    int preindex = 0;
    struct tree *root = build(inorder, preorder, 0, n - 1, &preindex);
    in_traverse(root);
    printf("\n");
    return 0;
}

*/
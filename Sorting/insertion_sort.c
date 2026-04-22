#include <stdio.h>

void insertion_sort_iterative(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

void insertion_sort_recursive(int a[], int start, int stop) {
    if (start > stop) return;
    int key = a[start];
    int j = start - 1;
    while (j >= 0 && a[j] > key) {
        a[j + 1] = a[j];
        j--;
    }
    a[j + 1] = key;
    insertion_sort_recursive(a, start + 1, stop);
}

int main() {
    int a[] = {42, 77, 35, 12, 101, 5};
    int b[] = {42, 77, 35, 12, 101, 5};
    
    insertion_sort_iterative(a, 6);
    for (int i = 0; i < 6; i++)
        printf("%d ", a[i]);
    printf("\n");
    
    insertion_sort_recursive(b, 0, 5);
    for (int i = 0; i < 6; i++)
        printf("%d ", b[i]);
    printf("\n");
    
    return 0;
}
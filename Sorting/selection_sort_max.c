#include <stdio.h>

void selection_sort_iterative(int a[], int n) {
    for (int i = 0; i < n; i++) {
        int max_i = 0;
        for (int j = 0; j <= n - i - 1; j++) {
            if (a[j] > a[max_i])
                max_i = j;
        }
        int temp = a[max_i];
        a[max_i] = a[n - i - 1];
        a[n - i - 1] = temp;
    }
}

void selection_sort_recursive(int a[], int n) {
    if (n < 1) return;
    int max_i = 0;
    for (int j = 0; j < n; j++) {
        if (a[j] > a[max_i])
            max_i = j;
    }
    int temp = a[max_i];
    a[max_i] = a[n - 1];
    a[n - 1] = temp;
    selection_sort_recursive(a, n - 1);
}

int main() {
    int a[] = {42, 77, 35, 12, 101, 5};
    int b[] = {42, 77, 35, 12, 101, 5};
    
    selection_sort_iterative(a, 6);
    for (int i = 0; i < 6; i++)
        printf("%d ", a[i]);
    printf("\n");
    
    selection_sort_recursive(b, 6);
    for (int i = 0; i < 6; i++)
        printf("%d ", b[i]);
    printf("\n");
    
    return 0;
}
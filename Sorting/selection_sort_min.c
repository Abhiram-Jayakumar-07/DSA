#include <stdio.h>

void selection_sort_iterative(int a[], int n) {
    for (int i = 0; i < n; i++) {
        int min_i = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min_i])
                min_i = j;
        }
        int temp = a[min_i];
        a[min_i] = a[i];
        a[i] = temp;
    }
}

void selection_sort_recursive(int a[], int start, int stop) {
    if (start > stop) return;
            int min_i = start;
    for (int j = start; j <= stop; j++) {
        if (a[j] < a[min_i])
            min_i = j;
    }
    int temp = a[min_i];
    a[min_i] = a[start];
    a[start] = temp;
    selection_sort_recursive(a, start + 1, stop);
}

int main() {
    int a[] = {42, 77, 35, 12, 101, 5};
    int b[] = {42, 77, 35, 12, 101, 5};
    
    selection_sort_iterative(a, 6);
    for (int i = 0; i < 6; i++)
        printf("%d ", a[i]);
    printf("\n");
    
    selection_sort_recursive(b, 0, 5);
    for (int i = 0; i < 6; i++)
        printf("%d ", b[i]);
    printf("\n");
    
    return 0;
}
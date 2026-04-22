#include <stdio.h>

void bubble_sort_iterative(int a[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = temp;
            }
        }
    }
}

void bubble_sort_recursive(int a[], int n) {
    if (n < 1)
        return;
    for (int j = 0; j < n - 1; j++) {
        if (a[j] > a[j + 1]) {
            int temp = a[j + 1];
            a[j + 1] = a[j];
            a[j] = temp;
        }
    }
    bubble_sort_recursive(a, n - 1);
}

int main() {
    int a[] = {42, 77, 35, 12, 101, 5};
    bubble_sort_iterative(a, 6);
    for (int i = 0; i < 6; i++)
        printf("%d ", a[i]);
    printf("\n");
    
    int b[] = {42, 77, 35, 12, 101, 5};
    bubble_sort_recursive(b, 6);
    for (int i = 0; i < 6; i++)
        printf("%d ", b[i]);
    printf("\n");
    
    return 0;
}
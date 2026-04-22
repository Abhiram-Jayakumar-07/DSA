#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[], int left, int right) {
    int pivot = a[left];
    int i = left;
    int j = right + 1;
    while (1) {
        do { i++; } while(i <= right && a[i] <= pivot);
        do { j--; } while (a[j] > pivot);
        if (i >= j) break;
        swap(&a[i], &a[j]);
    }
    swap(&a[left], &a[j]);
    return j;
}

void quick_sort(int a[], int left, int right) {
    if (left >= right) return;
    int j = partition(a, left, right);
    quick_sort(a, left, j);
    quick_sort(a, j + 1, right);
}

int main() {
    int a[] = {42, 77, 35, 12, 101, 5};
    int n = 6;

    quick_sort(a, 0, n - 1);

    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}
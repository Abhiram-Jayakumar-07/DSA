#include <stdio.h>

void merge(int a[], int b[], int left, int mid, int right) {
    int n1 = left, n2 = mid + 1, i = left;
    while (n1 <= mid && n2 <= right) {
        if (a[n1] <= a[n2])
            b[i++] = a[n1++];
        else
            b[i++] = a[n2++];
    }
    while (n1 <= mid)
        b[i++] = a[n1++];
    while (n2 <= right)
        b[i++] = a[n2++];
    for (i = left; i <= right; i++)
        a[i] = b[i];
}

void merge_sort(int a[], int b[], int left, int right) {
     if (left >= right)
         return;
     int mid = (left + right) / 2;
     merge_sort(a, b, left, mid);
     merge_sort(a, b, mid + 1, right);
     merge(a, b, left, mid, right);
}

int main() {
    int a[] = {42, 77, 35, 12, 101, 5};
    int n = 6;

    int b[n];   // shared temporary array

    merge_sort(a, b, 0, n - 1);

    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}
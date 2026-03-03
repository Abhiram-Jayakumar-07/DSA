#include <iostream>

void insertion_sort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int key = a[i], j;
        for (j = i - 1; j >= 0 && a[j] > key; j--)
            a[j + 1] = a[j];
        a[j + 1] = key;
    }
}

int main() {
    int a[] = {1, 4, 3, 5, 9, 10, 6, 14, 19, 18, 13, 21};
    insertion_sort(a, 12);
    for (int i = 0; i < 12; i++)
        std::cout << a[i] << " ";
    std::cout << "\n";
    
    return 0;
}
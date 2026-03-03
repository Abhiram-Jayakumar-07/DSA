#include <iostream>

void insertion_sort(int a[], int n) {
    if (n <= 1) return;
    
    insertion_sort(a, n - 1);
    
    int key = a[n - 1];
    int j = n - 2;
    while (j >= 0 && a[j] > key) {
        a[j + 1] = a[j];
        j--;
    }
    a[j + 1] = key;
}

int main() {
    int a[] = {1, 4, 3, 5, 9, 10, 6, 14, 19, 18, 13, 21};
    insertion_sort(a, 12);
    for (int i = 0; i < 12; i++)
        std::cout << a[i] << " ";
    std::cout << "\n";
    
    return 0;
}
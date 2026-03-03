#include <iostream>
#include <utility>

void bubble_sort(int a[], int n) {
    if (n <= 1) return;
    
    int swapped = 0;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1]) {
            std::swap(a[i], a[i + 1]);
            swapped = 1;
        }
    }
    
    if (!swapped) return;
    
    bubble_sort(a, n - 1);
}

int main() {
    int a[] = {1, 4, 3, 5, 9, 10, 6, 14, 19, 18, 13, 21};
    bubble_sort(a, 12);
    for (int i = 0; i < 12; i++)
        std::cout << a[i] << " ";
    std::cout << "\n";
    
    return 0;
}
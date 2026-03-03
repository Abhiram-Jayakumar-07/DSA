#include <iostream>
#include <utility>

int partition(int a[], int l, int r) {
    int i = l - 1;
    for (int j = l; j < r; j++)
        if (a[j] <= a[r])
            std::swap(a[++i], a[j]);
    std::swap(a[i + 1], a[r]);
    return i + 1;
}

void quick_sort(int a[], int l, int r) {
    if (l >= r) return;
    
    int p = partition(a, l, r);
    quick_sort(a, l, p - 1);
    quick_sort(a, p + 1, r);
}

int main() {
    int a[] = {1, 4, 3, 5, 9, 10, 6, 14, 19, 18, 13, 21};
    quick_sort(a, 0, 12 - 1);
    for (int i = 0; i < 12; i++)
        std::cout << a[i] << " ";
    std::cout << "\n";
    
    return 0;
}
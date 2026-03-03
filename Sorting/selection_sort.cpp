#include <iostream>
// #include <utility>

void selection_sort(int a[], int start, int stop) {
    if (start >= stop) return;
    
    int min = start;
    for (int i = start + 1; i <= stop; i++) {
        if (a[i] < a[min])
            min = i;
    }
    
    // Alternative: use std::swap(a[min], a[start]) included via utility.
    int temp = a[min];
    a[min] = a[start];
    a[start] = temp;
    
    selection_sort(a, start + 1, stop);
}

int main() {
    int a[] = {1, 4, 3, 5, 9, 10, 6, 14, 19, 18, 13, 21};
    selection_sort(a, 0, 12 - 1);
    for (int i = 0; i < 12; i++)
        std::cout << a[i] << " ";
    std::cout << "\n";
    
    return 0;
}
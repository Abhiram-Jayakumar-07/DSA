#include <iostream>

void rotate(int a[], int n) {
    int first = a[0];
    for (int i = 1; i < n; i++)
        a[i - 1] = a[i];
    a[n - 1] = first;
}

int main() {
    int a[] = {1, 2, 3, 4, 5};
    rotate(a, 5);
    for (int i: a)
        std::cout << i << " ";
    std::cout << "\n";
    return 0;
}
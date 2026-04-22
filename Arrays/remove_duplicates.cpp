#include <iostream>

int remove_duplicates(int a[], int n) {
    int c = 0;
    for (int i = 0; i < n - 1; i++)
        if (a[i] != a[i + 1])
            a[c++] = a[i];
    a[c++] = a[n - 1];
    return c;
}

int main() {
    int a[] = {0, 0, 0, 1, 1, 1, 2, 3, 3, 4, 5, 5, 5, 5, 5};
    int k = remove_duplicates(a, 15);
    for (int i = 0; i < k; i++)
        std::cout << a[i] << " ";
    std::cout << "\n";
    return 0;
}
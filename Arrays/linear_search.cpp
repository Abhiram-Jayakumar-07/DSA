#include <iostream>

int linear_search(int a[], int n, int k) {
    for (int i = 0; i < n; i++)
        if (a[i] == k)
            return i;
    return -1;
}

int main() {
    int a[] = {1, 2, 3, 4, 5};
    std::cout << linear_search(a, 5, 3) << "\n";
    return 0;
}
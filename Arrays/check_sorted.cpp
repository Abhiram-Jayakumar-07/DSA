#include <iostream>

    bool check_sorted(const int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1])
            return false;
    }
    return true;
}

int main() {
    int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int b[] = {0, 1, 2, 3, 4, 5, 6, 7, 9, 8};
    int c[] = {0, 1, 2, 3, 4, 5, 6, 7, 9, 9};
    std::cout << check_sorted(a, 10) << "\n";
    std::cout << check_sorted(b, 10) << "\n";
    std::cout << check_sorted(c, 10) << "\n";
    return 0;
}
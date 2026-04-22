#include <iostream>

int binary_search(int a[], int l, int u, int target) {
    int mid = l + (u - l) / 2;
    if (l > u)
        return -1;
    if (a[mid] > target)
        return binary_search(a, l, mid - 1, target);
    if (a[mid] < target)
        return binary_search(a, mid + 1, u, target);
    return mid;
}

int main() {
    int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::cout << binary_search(a, 0, 9, 5) << "\n";
    return 0;
}
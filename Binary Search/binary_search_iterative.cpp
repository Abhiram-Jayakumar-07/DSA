#include <iostream>

int binary_search(int a[], int n, int target) {
    int l = 0, u = n - 1;
    while (l <= u) {
        int mid = l + (u - l) / 2;
        if (a[mid] > target)
            u = mid - 1;
        else if (a[mid] < target)
            l = mid + 1;
        else
            return mid;
    }
    return -1;
}

int main() {
    int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::cout << binary_search(a, 10, 5) << "\n";
    return 0;
}
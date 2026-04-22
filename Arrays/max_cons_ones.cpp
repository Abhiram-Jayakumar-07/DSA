#include <iostream>

int max_cons_ones(int a[], int len) {
    int c = 0, p = 0;
    for (int i = 0; i < len; i++) {
        if (a[i] == 0) {
            p = std::max(c, p);
            c = 0;
        }
        else
            c++;
    }
    return std::max(c, p);
}

int main() {
    int a[] = {1, 0, 1, 1, 0, 1};
    std::cout << max_cons_ones(a, 6) << "\n";
    return 0;
}
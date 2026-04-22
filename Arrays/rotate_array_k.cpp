#include <iostream>
#include <utility>

void reverse(int a[], int b, int e) {
    while (b < e)
        std::swap(a[b++], a[e--]);
}
void rotate(int a[], int n, int k, int s) {
    if (k == 0 || n == 0) return;
    
    k = k % n;
    if (s < 0)
        k = n - k;
    
    reverse(a, 0, n - 1);
    reverse(a, 0, k - 1);
    reverse(a, k, n - 1);
    
}

int main() {
    int a[] = {1, 2, 3, 4, 5, 6, 7};
    int b[] = {1, 2, 3, 4, 5, 6};
    
    rotate(a, 7, 2, 1);
    rotate(b, 6, 2, -1);
    
    for (int i: a)
        std::cout << i << " ";
    std::cout << "\n";
    
    for (int i: b)
        std::cout << i << " ";
    std::cout << "\n";
    
    return 0;
}

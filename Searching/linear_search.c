#include <stdio.h>
#include <stdbool.h>

bool linear_search(int a[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (a[i] == key)
            return true;
    }
    return false;
}

int main() {
    int a[] = {4, 8, 19, 25, 34, 39, 45, 48, 66, 75, 89, 95};
    printf("%d\n", linear_search(a, 12, 89));
    return 0;
}
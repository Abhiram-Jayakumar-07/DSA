#include <iostream>

int* array_union(int a1[], int a2[], int n1, int n2) {
    int a[n1 + n2];
    int i = 0, c = 0;
    while (i < n1 && i < n2) {
        if (a1[i] < a2[i] && a1[i] != a[c]) {
            a[c++] = a1[i];
        } else {
            if (a2[i] != a[c])
                a[c++] = a2[i];
        }
    }
    if (n1 < n2) {
        while (i < n2)
            a[c++] = a2[i++];
    } else {
        while (i < n2)
            a[c++] = a2[i++];
    }
    return a;
}

int main() {
    int a[] = {1, 2, 3, 4, 5}, b[] = {2, 3, 4, 4, 5};
    int *c = array_union(a, b, 5, 5);
    for (int i = 0; i < )
}
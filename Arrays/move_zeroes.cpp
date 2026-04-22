#include <iostream>
#include <utility>

void move_zeroes(int a[], int len) {
    int l = 0;
    for (int r = 0; r < len; r++)
        if (a[r] != 0)
            std::swap(a[l++], a[r]);
}

int main() {
    int a[] = {1, 0, 2, 3, 0, 4, 0, 1};
    move_zeroes(a, 8);
    for (int i: a)
        std::cout << i << " ";
    std::cout << "\n";
    return 0;
}


/*
 My solution
 
 void move_zeroes(int a[], int len) {
     int n = 0;
     for (int i = 0; i < len; i++) {
         if (a[i] != 0) {
             a[n++] = a[i]; 
         }
     }
     while (n < len)
         a[n++] = 0;
 }
  
 */

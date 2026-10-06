#include <iostream>
using namespace std;

int main() {
    unsigned int n, k;
    cin >> n >> k;

    n = n | (1 << k);
    cout << n;

    return 0;
}
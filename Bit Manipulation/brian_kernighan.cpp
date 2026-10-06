#include <iostream>
using namespace std;

int main() {
    unsigned int n;
    unsigned int count = 0;

    cin >> n;

    while (n) {
        count++;
        n &= n - 1;
    }

    cout << count;

    return 0;
}

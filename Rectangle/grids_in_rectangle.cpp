#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    cout << n * m * (n+1) * (m+1) / 4 << "\n";
    return 0;
}
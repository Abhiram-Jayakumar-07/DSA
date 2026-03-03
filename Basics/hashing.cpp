#include <iostream>
using std::cout, std::cin;

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Precompute
    int hash[100] = {0};
    for (int i = 0; i < n; i++) {
        hash[arr[i]] += 1;
    }

    // Fetching
    int q;
    cin >> q;
    while (q--) {
        int num;
        cin >> num;
        cout << hash[num] << " ";
    }
    cout << "\n";

    return 0;
}

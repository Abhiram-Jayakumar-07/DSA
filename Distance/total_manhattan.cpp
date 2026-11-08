#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> x(n);
    vector<int> y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += (2 * i - n + 1) * (x[i] + y[i]);
    }

    cout << sum << '\n';
}

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    double a[n][n + 1];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        double ratio = a[i][i];
        for (int j = 0; j <= n; j++) {
            a[i][j] = a[i][j] / ratio;
        }

        for (int k = 0; k < n; k++) {
            if (k != i) {
                ratio = a[k][i];
                for (int j = 0; j <= n; j++) {
                    a[k][j] -= ratio * a[i][j];
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << 'x' << (i + 1) << " = " << a[i][n] << "\n";
    }

    return 0;
}

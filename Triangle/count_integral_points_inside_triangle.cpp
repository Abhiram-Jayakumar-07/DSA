#include <iostream>
#include <numeric>
using namespace std;

int main() {
    int x1, y1;
    int x2, y2;
    int x3, y3;

    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> x3 >> y3;

    int B = 0;
    B += gcd(abs(x1-x2), abs(y1-y2));
    B += gcd(abs(x2-x3), abs(y2-y3));
    B += gcd(abs(x3-x1), abs(y3-y1));

    int A = abs(x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2)); // Here 'A' holds the value 2 * area of triangle
    int I = (A - B + 2) / 2;

    cout << I << "\n";

    return 0;
}

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    long long n;
    cin >> n;

    double x = (sqrt(1 + 8 * n) - 1) / 2;
    cout << (floor(x) == x);

    return 0;
}
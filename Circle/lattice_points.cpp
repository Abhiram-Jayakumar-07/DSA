#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int r, count = 4;
    cin >> r;

    for (int x = 1; x <= r - 1; x++)
    {
        int y2 = r * r - x * x;
        int y = round(sqrt(y2));
        if (y * y == y2)
            count += 4;
    }

    cout << count;

    return 0;
}

#include <iostream>
using namespace std;

int main()
{
    int n, count = 0;
    cin >> n;

    for (int l = 1; l * l <= n; l++)
    {
        count += n / l - l + 1;
    }

    cout << count << "\n";
    return 0;
}

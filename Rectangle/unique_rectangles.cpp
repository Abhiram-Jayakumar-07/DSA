#include <iostream>
using namespace std;

int main()
{
    int n, count = 0;
    cin >> n;

    for (int l = 1; l * l <= n; l++)
    {
        for (int h = l; h * l <= n; h++)
        {
            count++;
        }
    }

    cout << count << "\n";
    return 0;
}

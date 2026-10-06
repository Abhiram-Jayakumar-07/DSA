#include <iostream>
using namespace std;

int main()
{
    unsigned int n, k;
    cin >> n >> k;

    if (n & (1 << k))
    {
        cout << "SET\n";
    }
    else
    {
        cout << "UNSET\n";
    }

    return 0;
}
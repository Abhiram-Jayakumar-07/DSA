#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void search(string pat, string txt)
{
    int m = pat.size();
    int n = txt.size();
    int d = 256;
    int q = 101;
    int p = 0;
    int t = 0;
    int h = (int)pow(d, m - 1) % q;

    for (int i = 0; i < m; i++)
    {
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }

    for (int i = 0; i <= n - m; i++)
    {
        if (p == t)
        {
            int j;
            for (j = 0; j < m; j++)
            {
                if (pat[j] != txt[i + j])
                    break;
            }

            if (j == m)
                cout << i << '\n';
        }

        if (i < n - m)
        {
            t = (d * (t - txt[i] * h) + txt[i + m]) % q;
            if (t < 0)
                t += q;
        }
    }
}

int main()
{
    string pat, txt;
    cin >> pat >> txt;

    search(pat, txt);

    return 0;
}

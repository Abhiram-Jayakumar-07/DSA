#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> compute_lps(string pat) {
    int m = pat.length();
    int i = 1, len = 0;
    vector<int> lps(m, 0);

    while (i < m) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

void kmp(string txt, string pat) {
    int n = txt.length();
    int m = pat.length();
    if (n < m || m == 0)
        return;

    vector<int> lps = compute_lps(pat);

    int i = 0;
    int j = 0;
    while (i < n) {
        if (txt[i] == pat[j]) {
            i++;
            j++;
            if (j == m) {
                cout << i - j << '\n';
                j = lps[j - 1];
            }
        } else {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
}

int main() {
    string txt = "abcabc";
    string pat = "abc";
    kmp(txt, pat);
    return 0;
}

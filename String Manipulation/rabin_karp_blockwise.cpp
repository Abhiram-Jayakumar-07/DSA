#include <iostream>
#include <string>
using namespace std;

void rabin_karp(string text, string pattern) {
  int n = text.length();
  int m = pattern.length();
  if (m > n)
    return;

  int h = 1;
  for (int i = 0; i < m - 1; i++) {
    h = (256 * h) % 101;
  }

  int t = 0;
  int p = 0;
  for (int i = 0; i < m; i++) {
    t = (256 * t + text[i]) % 101;
    p = (256 * p + pattern[i]) % 101;
  }

  int next_valid_index = 0;
  for (int i = 0; i <= n - m; i++) {
    if (t == p) {
      bool match = true;
      if (i >= next_valid_index) {
        for (int j = 0; j < m; j++) {
          if (text[i + j] != pattern[j]) {
            match = false;
            break;
          }
        }

        if (match) {
          cout << i << '\n';
          next_valid_index = i + m;
        }
      }
    }

    if (i < n - m) {
      t = (256 * (t - text[i] * h) + text[i + m]) % 101;
      if (t < 0) {
        t += 101;
      }
    }
  }
}

int main() {
  string text = "abcabc";
  string pattern = "abc";
  rabin_karp(text, pattern);
  return 0;
}

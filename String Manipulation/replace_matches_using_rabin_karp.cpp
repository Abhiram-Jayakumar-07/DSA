#include <iostream>
#include <string>
#include <vector>
using namespace std;

void replace(string text, string pattern) {
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

  vector<int> matches;
  for (int i = 0; i <= n - m; i++) {
    if (t == p) {
      bool match = true;
      for (int j = 0; j < m; j++) {
        if (text[i + j] != pattern[j]) {
          match = false;
          break;
        }
      }

      if (match) {
        matches.push_back(i);
      }
    }

    if (i < n - m) {
      t = (256 * (t - text[i] * h) + text[i + m]) % 101;
      if (t < 0) {
        t += 101;
      }
    }
  }

  for (int i : matches) {
    for (int j = 0; j<m; j++){
      text[i+j] = '*';
    }
  }

  cout << text << '\n';
}

int main() {
  string text = "abcabc";
  string pattern = "abc";
  replace(text, pattern);
  return 0;
}

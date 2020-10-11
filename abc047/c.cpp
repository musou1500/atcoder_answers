#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  string s;
  cin >> s;

  int cnt_b = 0, cnt_w = 0, i = 0;
  while (i < s.size()) {
    int cur = i;
    while (cur < s.size() && s[i] == s[cur]) {
      cur++;
    }

    if (s[i] == 'B') {
      cnt_b++;
    } else {
      cnt_w++;
    }

    i = cur;
  }

  cout << cnt_b + cnt_w - 1 << '\n';
  return 0;
}

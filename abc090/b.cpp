#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int a, b;
  cin >> a >> b;

  auto solve = [](string &s) {
    bool res = true;
    for (int i = 0; i < s.size() / 2; ++i) {
      if (s[i] != s[s.size() - i - 1]) {
        res = false;
        break;
      }
    }

    return res;
  };

  int ans = 0;
  for (int i = a; i <= b; ++i) {
    string s = to_string(i);
    if (solve(s)) {
      ans++;
    }
  }

  cout << ans << '\n';
  return 0;
}

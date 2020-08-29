#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  //
  string s, t;
  cin >> s >> t;

  int ans = -1;
  for (int i = 0; i < s.size() - t.size() + 1; ++i) {
    int cnt = 0;
    for (int j = 0; j < t.size(); ++j) {
      if (s[i + j] != t[j]) {
        cnt++;
      }
    }

    if (ans < 0 || ans > cnt) {
      ans = cnt;
    }
  }

  cout << ans << '\n';
  return 0;
}

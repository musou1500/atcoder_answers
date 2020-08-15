#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  //
  string s;
  cin >> s;

  int cur = 0, ans = 0;
  while (cur < s.size()) {
    if (s[cur] != 'R') {
      cur++;
      continue;
    }

    int cur2 = cur;
    while (cur2 < s.size() && s[cur2] == 'R') {
      cur2++;
    }

    ans = max(ans, cur2 - cur);
    cur = cur2;
  }

  cout << ans << '\n';
  return 0;
}

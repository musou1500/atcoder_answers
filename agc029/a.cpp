#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  string s;
  cin >> s;

  long long ans = 0, w_cnt = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'W') {
      ans += i - w_cnt;
      w_cnt++;
    }
  }

  cout << ans << '\n';
  return 0;
}


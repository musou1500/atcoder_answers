#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  string s, t;
  cin >> s >> t;
  int ans = 0;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] != t[i]) {
      ans++;
    }
  }

  cout << ans << '\n';
  return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  string s;
  cin >> s;

  auto chk = [](string &s, int len) {
    bool ans = true;
    for (int i = 0; i < len / 2; ++i) {
      if (s[i] != s[i + len / 2]) {
        ans = false;
        break;
      }
    }

    return ans;
  };

  int ans;
  for (int i = 2; i < s.size(); i += 2) {
    if (chk(s, s.size() - i)) {
      ans = s.size() - i;
      break;
    }
  }

  cout << ans << '\n';
  return 0;
}

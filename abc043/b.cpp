#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  string s;
  cin >> s;

  vector<char> chs;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == 'B') {
      if (chs.size() > 0) {
        chs.erase(chs.end() - 1);
      }
    } else {
      chs.push_back(s[i]);
    }
  }

  string ans(chs.begin(), chs.end());
  cout << ans << '\n';
  return 0;
}

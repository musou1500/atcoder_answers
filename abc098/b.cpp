#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int n;
  string s;
  cin >> n >> s;

  int ans = 0;
  for (int i = 0; i < s.size(); ++i) {
    set<char> cnt1, cnt2;
    for (int j = 0; j < s.size(); j++) {
      if (j > i) {
        cnt2.insert(s[j]);
      } else {
        cnt1.insert(s[j]);
      }
    }

    int cnt = 0;
    for (auto it = cnt1.begin(); it != cnt1.end(); it++) {
      if (cnt2.count(*it) > 0) {
        cnt++;
      }
    }

    ans = max(ans, cnt);
  }

  cout << ans << '\n';
  return 0;
}


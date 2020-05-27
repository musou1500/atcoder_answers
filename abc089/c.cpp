#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  array<long long, 256> cnts{0};
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    cnts[s[0]]++;
  }

  string chs = "MARCH";
  long long ans = 0;
  for (int i = 0; i < chs.size() - 2; ++i) {
    for (int j = i + 1; j < chs.size() - 1; ++j) {
      for (int k = j + 1; k < chs.size(); ++k) {
        ans += cnts[chs[i]] * cnts[chs[j]] * cnts[chs[k]];
      }
    }
  }

  cout << ans << '\n';

  return 0;
}

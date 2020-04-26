#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  string s;
  cin >> s;

  vector<int> mods(s.size());
  mods[s.size() - 1] = s.back() - '0';
  int p = 10;
  for (int i = s.size() - 2; i >= 0; i--) {
    int d = s[i] - '0';
    mods[i] = (p * d + mods[i + 1]) % 2019;
    p = p * 10 % 2019;
  }

  vector<int> cnts(2019, 0);
  cnts[0]++;
  for (int i = 0; i < mods.size(); i++) {
    cnts[mods[i]]++;
  }

  long long ans = 0;
  for (auto c : cnts) {
    ans += c * (c - 1) / 2;
  }

  cout << ans << '\n';

  return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  using ll = long long;
  int n;
  cin >> n;

  vector<ll> va(n);
  unordered_map<ll, vector<int>> l_dict, r_dict;
  for (int i = 0; i < n; ++i) {
    cin >> va[i];
    int l = i - va[i], r = va[i] + i;
    l_dict[l].push_back(i);
    r_dict[r].push_back(i);
  }

  ll ans = 0;
  for (auto [l, indices] : l_dict) {
    ans += indices.size() * r_dict[l].size();
  }

  cout << ans << '\n';

  return 0;
}

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll solve(vector<vector<ll>> &v, int i, int j, vector<vector<ll>> &memo) {
  if (i == v.size()) {
    return 1;
  }

  if (j >= v[i].size()) {
    return 0;
  }

  if (memo[i][j] == -1) {
    ll ans = solve(v, i, j + 1, memo);

    if (i + 1 < v.size()) {
      auto it = upper_bound(v[i + 1].begin(), v[i + 1].end(), v[i][j]);
      ans += solve(v, i + 1, distance(v[i + 1].begin(), it), memo);
    } else {
      ans++;
    }

    memo[i][j] = ans;
  }

  return memo[i][j];
}

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;

  vector<ll> va(n), vb(n), vc(n);
  for (int i = 0; i < n; ++i) cin >> va[i];
  for (int i = 0; i < n; ++i) cin >> vb[i];
  for (int i = 0; i < n; ++i) cin >> vc[i];

  sort(va.begin(), va.end());
  sort(vb.begin(), vb.end());
  sort(vc.begin(), vc.end());

  vector<vector<ll>> memo(5, vector<ll>(n + 10, -1));
  vector<vector<ll>> v{va, vb, vc};
  cout << solve(v, 0, 0, memo) << '\n';

  return 0;
}

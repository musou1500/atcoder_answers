#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

ll solve(const vector<pair<ll, ll>> &va, vector<vector<ll>> &memo, int l = 0,
         int r = 0) {
  if (l + r == va.size()) {
    return 0;
  }

  if (memo[l][r] < 0) {
    auto [a, idx] = va[l + r];
    ll n = static_cast<ll>(va.size());
    memo[l][r] = max(solve(va, memo, l + 1, r) + a * abs(idx - l),
                     solve(va, memo, l, r + 1) + a * abs(idx - (n - r - 1)));
  }

  return memo[l][r];
}

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;

  vector<pair<ll, ll>> va;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    va.push_back({a, i});
  }

  sort(va.begin(), va.end(), greater<pair<ll, ll>>());
  vector<vector<ll>> memo(n + 1, vector<ll>(n + 1, -1));
  cout << solve(va, memo) << '\n';
  return 0;
}

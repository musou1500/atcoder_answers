#include <bits/stdc++.h>
#include <algorithm>
#include <functional>
#include <iterator>
#include <numeric>

using namespace std;

using ll = long long;

ll solve(vector<ll> &v, int l, int r, int k) {
  vector<ll> v2;
  if (l + r >= v.size()) {
    copy(v.begin(), v.end(), back_inserter(v2));
  } else {
    copy(v.begin(), v.begin() + l, back_inserter(v2));
    copy(v.rbegin(), v.rbegin() + r, back_inserter(v2));
  }

  sort(v2.begin(), v2.end());

  ll ans = 0;
  for (int i = 0; i < v2.size(); ++i) {
    if (i < k - (l + r) && v2[i] < 0) {
      continue;
    }

    ans += v2[i];
  }

  return ans;
}

int main(int argc, const char *argv[]) {
  int n, k;
  cin >> n >> k;

  vector<ll> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }

  ll ans = 0;
  for (int i = 0; i <= k; ++i) {
    for (int j = 0; j <= k - i; ++j) {
      ans = max(ans, solve(v, i, j, k));
    }
  }

  cout << ans << '\n';
  return 0;
}

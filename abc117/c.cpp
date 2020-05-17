#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  using ll = long long;
  ll n, m;
  cin >> n >> m;
  vector<ll> vx(m);
  for (ll i = 0; i < m; ++i) {
    cin >> vx[i];
  }

  sort(vx.begin(), vx.end());
  n--;

  vector<ll> dists;
  for (ll i = 1; i < m; ++i) {
    dists.push_back(vx[i] - vx[i - 1]);
  }

  sort(dists.begin(), dists.end(), greater<ll>());

  ll ans = 0;
  for (int i = n; i < dists.size(); ++i) {
    ans += dists[i];
  }

  cout << ans << '\n';

  return 0;
}

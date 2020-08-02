#include <bits/stdc++.h>
#include <vector>

using namespace std;
using ll = long long;
int main(int argc, const char *argv[]) {
  ll n, d;
  cin >> n >> d;
  vector<pair<ll, ll>> vp(n);
  for (int i = 0; i < n; ++i) {
    cin >> vp[i].first >> vp[i].second;
  }

  ll ans = 0;
  for (auto &p : vp) {
    ll dist = p.first * p.first + p.second * p.second;
    if (dist <= d * d) {
      ans++;
    }
  }

  cout << ans << '\n';
  return 0;
}

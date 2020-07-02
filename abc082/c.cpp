#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;
  vector<ll> va(n);
  map<ll, ll> cnts;
  for (int i = 0; i < n; ++i) {
    cin >> va[i];
    cnts[va[i]]++;
  }

  ll ans = 0;
  for (auto p : cnts) {
    if (p.first > p.second) {
      ans += p.second;
    } else {
      ans += p.second - p.first;
    }
  }

  cout << ans << '\n';
  return 0;
}

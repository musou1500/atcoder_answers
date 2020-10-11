#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;
  vector<ll> va(n);
  for (int i = 0; i < n; ++i) {
    cin >> va[i];
  }

  sort(va.begin(), va.end(), greater<ll>());

  vector<ll> vb;
  for (int i = 1; i < va.size(); ++i) {
    vb.push_back(va[i]);
    vb.push_back(va[i]);
  }

  ll ans = va.front();
  for (int i = 0; i < n - 2; ++i) {
    ans += vb[i];
  }

  cout << ans << '\n';
  return 0;
}

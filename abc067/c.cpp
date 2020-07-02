#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;

  vector<ll> va{0};
  for (int i = 0; i < n; ++i) {
    ll a;
    cin >> a;
    va.push_back(va.back() + a);
  }

  ll sum = va.back();
  ll ans = -1;
  for (int i = 0; i < n - 1; ++i) {
    ll snk = va[i + 1];
    ll ari = sum - snk;
    ll diff = abs(snk - ari);
    if (ans < 0 || ans > diff) {
      ans = diff;
    }
  }

  cout << ans << '\n';
  return 0;
}

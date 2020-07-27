#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(int argc, const char *argv[]) {
  int n;
  ll k;
  cin >> n >> k;

  vector<ll> cnts(200000, 0);
  for (int i = 0; i < n; ++i) {
    int a;
    ll b;
    cin >> a >> b;
    cnts[a] += b;
  }

  ll acc = 0, ans = 0;
  for (int i = 1; i < cnts.size(); ++i) {
    acc += cnts[i];
    if (acc >= k) {
      ans = i;
      break;
    }
  }

  cout << ans << '\n';

  return 0;
}

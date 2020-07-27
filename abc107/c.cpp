#include <bits/stdc++.h>
#include <algorithm>
#include <iterator>
#include <numeric>

using namespace std;
using ll = long long;

int main(int argc, const char *argv[]) {
  int n, k;
  cin >> n >> k;

  vector<ll> vx(n);
  for (int i = 0; i < n; ++i) {
    cin >> vx[i];
  }

  ll ans = -1;
  for (int i = 0; i < vx.size() - k + 1; ++i) {
    int dist = vx[i + k - 1] - vx[i];
    if (vx[i] >= 0) {
      dist += abs(vx[i]);
    } else if (vx[i + k - 1] <= 0) {
      dist += abs(vx[i + k - 1]);
    } else {
      dist += min(abs(vx[i]), abs(vx[i + k - 1]));
    }

    if (ans < 0 || ans > dist) {
      ans = dist;
    }
  }

  cout << ans << '\n';

  return 0;
}

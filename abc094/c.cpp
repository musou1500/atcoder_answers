#include <bits/stdc++.h>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

using ll = long long;

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;
  vector<pair<ll, ll>> vx(n);
  for (int i = 0; i < n; ++i) {
    cin >> vx[i].first;
    vx[i].second = i;
  }

  sort(vx.begin(), vx.end(), greater<pair<ll, ll>>());

  vector<ll> ans(n);
  int mid = n / 2 - 1;
  for (int i = 0; i < n; ++i) {
    if (i <= mid) {
      ans[vx[i].second] = vx[mid + 1].first;
    } else {
      ans[vx[i].second] = vx[mid].first;
    }
  }

  for (int i = 0; i < n; ++i) {
    cout << ans[i] << '\n';
  }

  return 0;
}

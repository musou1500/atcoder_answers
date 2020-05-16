#include <bits/stdc++.h>
#include <functional>

using namespace std;

int main(int argc, const char *argv[]) {
  using ll = long long;
  int x, y, z, k;
  cin >> x >> y >> z >> k;

  vector<ll> va(x), vb(y), vc(z);
  for (auto &a : va) {
    cin >> a;
  }

  for (auto &b : vb) {
    cin >> b;
  }

  for (auto &c : vc) {
    cin >> c;
  }

  vector<ll> sum_bc;
  for (auto &b : vb) {
    for (auto &c : vc) {
      sum_bc.push_back(b + c);
    }
  }

  sort(sum_bc.begin(), sum_bc.end(), greater<ll>());
  sort(va.begin(), va.end(), greater<ll>());
  vector<ll> ans;
  for (int i = 0; i < min(static_cast<int>(sum_bc.size()), k); ++i) {
    for (int j = 0; j < min(static_cast<int>(va.size()), k); ++j) {
      ans.push_back(sum_bc[i] + va[j]);
    }
  }

  sort(ans.begin(), ans.end(), greater<ll>());
  for (int i = 0; i < k; ++i) {
    cout << ans[i] << '\n';
  }

  return 0;
}

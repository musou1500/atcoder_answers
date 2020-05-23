#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  using ll = long long;
  int n;
  cin >> n;
  vector<ll> va(n);
  for (int i = 0; i < n; i++) {
    cin >> va[i];
  }

  auto calc_r = [](ll n, ll r) { return min(r, n - r); };
  auto n_it = max_element(va.begin(), va.end());
  auto r_it = va.begin();
  if (r_it == n_it) {
    r_it++;
  }

  for (auto it = va.begin(); it != va.end(); it++) {
    if (it != n_it && calc_r(*n_it, *it) > calc_r(*n_it, *r_it)) {
      r_it = it;
    }
  }

  cout << *n_it << ' ' << *r_it << '\n';
  return 0;
}


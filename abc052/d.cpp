#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(int argc, const char *argv[]) {
  int n;
  ll a, b;
  cin >> n >> a >> b;

  vector<ll> vx(n);
  for (int i = 0; i < n; ++i) {
    cin >> vx[i];
  }

  ll sum = 0;
  for (int i = 0; i < n - 1; ++i) {
    ll dist = vx[i + 1] - vx[i];
    sum += min(a * dist, b);
  }

  cout << sum << '\n';
}

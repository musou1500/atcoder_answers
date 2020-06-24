#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;
  set<ll> cnt;
  for (int i = 0; i < n; ++i) {
    ll a;
    cin >> a;
    if (cnt.count(a) > 0) {
      cnt.erase(a);
    } else {
      cnt.insert(a);
    }
  }

  cout << cnt.size() << '\n';
  return 0;
}

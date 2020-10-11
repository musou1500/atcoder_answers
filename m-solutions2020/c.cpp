#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(int argc, const char *argv[]) {
  //
  int n, k;
  cin >> n >> k;

  vector<ll> va(n);
  for (int i = 0; i < n; ++i) {
    cin >> va[i];
  }

  for (int i = k, l = 0; i < n; ++i, ++l) {
    if (va[l] < va[i]) {
      cout << "Yes" << '\n';
    } else {
      cout << "No" << '\n';
    }
  }

  return 0;
}

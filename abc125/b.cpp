#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;

  vector<int> vv(n), vc(n);
  for (int i = 0; i < n; ++i) {
    cin >> vv[i];
  }

  for (int i = 0; i < n; ++i) {
    cin >> vc[i];
  }

  int ans = 0;
  for (int i = 0; i < (1 << n); ++i) {
    int x = 0, y = 0;
    for (int j = 0; j < n; ++j) {
      if (i & (1 << j)) {
        x += vv[j];
        y += vc[j];
      }
    }

    ans = max(ans, x - y);
  }

  cout << ans << '\n';

  return 0;
}

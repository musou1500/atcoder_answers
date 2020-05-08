#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int main(int argc, const char *argv[]) {
  int n, m;
  cin >> n >> m;

  vector<int> vh(n);
  for (int i = 0; i < n; ++i) {
    cin >> vh[i];
  }

  vector<int> ma(n, 0);
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    ma[a] = max(ma[a], vh[b]);
    ma[b] = max(ma[b], vh[a]);
  }

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (vh[i] > ma[i]) {
      ans++;
    }
  }

  cout << ans << '\n';
  return 0;
}

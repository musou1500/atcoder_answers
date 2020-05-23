#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int n, m, x;
  cin >> n >> m >> x;

  set<int> va;
  for (int i = 0; i < m; ++i) {
    int a;
    cin >> a;
    va.insert(a);
  }

  int ans = 0;
  for (int i = x + 1; i <= n; ++i) {
    if (va.count(i)) {
      ans++;
    }
  }

  int ans2 = 0;
  for (int i = x - 1; i >= 0; --i) {
    if (va.count(i)) {
      ans2++;
    }
  }

  cout << min(ans, ans2) << '\n';
  return 0;
}

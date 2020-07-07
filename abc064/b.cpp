#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;
  vector<int> va(n);
  for (int i = 0; i < n; ++i) {
    cin >> va[i];
  }

  sort(va.begin(), va.end());
  int ans = 0;
  for (int i = 0; i < n - 1; ++i) {
    ans += va[i + 1] - va[i];
  }

  cout << ans << '\n';
  return 0;
}

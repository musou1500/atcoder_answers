#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;
  vector<int> vp(n);
  for (int i = 0; i < n; ++i) {
    cin >> vp[i];
  }

  int ans = 0;
  for (int i = 0; i < vp.size() - 1; ++i) {
    if (vp[i] == i + 1) {
      swap(vp[i], vp[i + 1]);
      ans++;
    }
  }

  if (vp.back() == n) {
    ans++;
  }

  cout << ans << '\n';
  return 0;
}

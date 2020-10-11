#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;
  vector<int> vp(n);
  for (int i = 0; i < n; ++i) {
    cin >> vp[i];
  }

  sort(vp.begin(), vp.end(), greater<int>());
  vp[0] = vp[0] / 2;
  int ans = accumulate(vp.begin(), vp.end(), 0);
  cout << ans << '\n';
  return 0;
}

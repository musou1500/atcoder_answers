#include <bits/stdc++.h>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, const char *argv[]) {
  int n, k;
  cin >> n >> k;
  vector<int> vp(n);
  for (int i = 0; i < n; ++i) {
    cin >> vp[i];
  }

  sort(vp.begin(), vp.end());
  int ans = 0;
  for (int i = 0; i < k; ++i) {
    ans += vp[i];
  }

  cout << ans << '\n';
  return 0;
}

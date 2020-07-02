#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int n, k;
  cin >> n >> k;
  vector<int> vl(n);
  for (int i = 0; i < n; ++i) {
    cin >> vl[i];
  }

  sort(vl.begin(), vl.end(), greater<int>());

  int ans = 0;
  for (int i = 0; i < k; ++i) {
    ans += vl[i];
  }

  cout << ans << '\n';

  return 0;
}

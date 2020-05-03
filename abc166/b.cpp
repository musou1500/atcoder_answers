#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int n, k;
  cin >> n >> k;

  vector<int> cnt(n, 0);
  for (int i = 0; i < k; ++i) {
    int d;
    cin >> d;
    for (int i = 0; i < d; ++i) {
      int idx;
      cin >> idx;
      idx--;

      cnt[idx]++;
    }
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (cnt[i] == 0) {
      ans++;
    }
  }

  cout << ans << '\n';
  return 0;
}

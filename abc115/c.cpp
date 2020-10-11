#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int n, k;
  cin >> n >> k;
  vector<int> vh(n);
  for (int i = 0; i < n; ++i) {
    cin >> vh[i];
  }

  sort(vh.begin(), vh.end());
  int ans = vh[k - 1] - vh[0];
  for (int i = 0; i < vh.size() - k + 1; ++i) {
    ans = min(ans, vh[i + k - 1] - vh[i]);
  }

  cout << ans << '\n';
  return 0;
}

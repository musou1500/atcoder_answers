#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;
  vector<int> cnts(200000, 0);
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    cnts[a]++;
  }

  int ans = 0;
  for (int i = 0; i < 150000; ++i) {
    int cnt = cnts[i] + cnts[i + 1];
    if (i != 0) {
      cnt += cnts[i - 1];
    }

    ans = max(ans, cnt);
  }

  cout << ans << '\n';
  return 0;
}

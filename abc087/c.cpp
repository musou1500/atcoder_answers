#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;

  vector<int> cnt1(n + 1, 0), cnt2(n + 1, 0);
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    cnt1[i + 1] = a + cnt1[i];
  }

  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    cnt2[i + 1] = a + cnt2[i];
  }

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int sum = cnt1[i + 1] + cnt2.back() - cnt2[i];
    ans = max(sum, ans);
  }

  cout << ans << '\n';
  return 0;
}

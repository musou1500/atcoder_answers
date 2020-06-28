#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;

  vector<int> va(n);
  for (int i = 0; i < n; ++i) {
    cin >> va[i];
  }

  int ans = -1;
  for (int i = -100; i <= 100; ++i) {
    int cost = 0;
    for (int j = 0; j < va.size(); ++j) {
      cost += pow(va[j] - i, 2);
    }

    if (ans < 0 || ans > cost) {
      ans = cost;
    }
  }

  cout << ans << '\n';
  return 0;
}

#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;
  vector<int> vl(n);
  for (int i = 0; i < n; i++) {
    cin >> vl[i];
  }

  sort(vl.begin(), vl.end());

  int ans = 0;
  for (int i = 0; i < n - 2; i++) {
    for (int j = i + 1; j < n - 1; j++) {
      int a = vl[i], b = vl[j];
      int lower = abs(a - b), upper = a + b;
      auto lower_it = upper_bound(vl.begin() + j + 1, vl.end(), lower);
      auto upper_it =
          upper_bound(vl.rbegin(), vl.rend() - j - 1, upper, greater<int>());
      if (lower_it != vl.end() && upper_it != vl.rend()) {
        int upper_idx = distance(vl.rbegin(), upper_it);
        int lower_idx = distance(vl.begin(), lower_it);
        ans += max(0, n - upper_idx - lower_idx);
      }
    }
  }

  cout << ans << '\n';

  return 0;
}

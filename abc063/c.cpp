#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;

  vector<int> vs(n);
  int sum = 0, min_s = 101;
  for (int i = 0; i < n; ++i) {
    cin >> vs[i];
    sum += vs[i];

    if (vs[i] % 10 != 0) {
      min_s = min(min_s, vs[i]);
    }
  }

  if (min_s > 100) {
    cout << 0 << '\n';
  } else if (sum % 10 == 0) {
    cout << sum - min_s << '\n';
  } else {
    cout << sum << '\n';
  }

  return 0;
}

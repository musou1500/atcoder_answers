#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int x;
  cin >> x;

  int ans = 1;
  for (int i = 2; i * i <= x; ++i) {
    int powi = i * i;
    for (int powi = i * i; powi <= x; powi *= i) {
      ans = max(ans, powi);
    }
  }

  cout << ans << '\n';
  return 0;
}


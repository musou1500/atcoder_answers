#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += i + 1;
  }
  cout << ans << '\n';
  return 0;
}

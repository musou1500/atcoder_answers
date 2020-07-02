#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int a, b;
  cin >> a >> b;
  int ans = (a + b) / 2;
  if ((a + b) % 2 != 0) {
    ans++;
  }

  cout << ans << '\n';
  return 0;
}

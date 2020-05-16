#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int a, b, c;
  cin >> a >> b >> c;
  int ans = min(b / a, c);
  cout << ans << '\n';
  return 0;
}

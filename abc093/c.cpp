#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int a, b, c;
  cin >> a >> b >> c;
  int mx = max({a, b, c});
  int diff = (mx - a) + (mx - b) + (mx - c);
  if (diff % 2 == 1) {
    diff += 3;
  }

  cout << diff / 2 << '\n';
  return 0;
}

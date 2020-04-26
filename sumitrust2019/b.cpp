#include <bits/stdc++.h>
#include <cmath>

using namespace std;

int main(int argc, const char *argv[]) {
  double n;
  cin >> n;

  int ans = -1;
  for (int i = 0; i < n * 2; i++) {
    if (floor(i * 1.08) == n) {
      ans = i;
      break;
    }
  }

  if (ans < 0) {
    cout << ":(\n";
  } else {
    cout << ans << '\n';
  }

  return 0;
}

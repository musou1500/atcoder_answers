#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int a, b;
  cin >> a >> b;

  int ans = a + b;
  if (ans < 10) {
    cout << ans << '\n';
  } else {
    cout << "error" << '\n';
  }

  return 0;
}

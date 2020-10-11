#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int w, a, b;
  cin >> w >> a >> b;
  if (a > b) {
    swap(a, b);
  }

  int r1 = w + a, r2 = w + b;
  cout << max(0, b - r1) << '\n';
  return 0;
}

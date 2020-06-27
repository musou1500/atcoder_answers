#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int start = max(a, c), end = min(b, d);
  cout << max(0, end - start) << '\n';
  return 0;
}

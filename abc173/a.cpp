#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;

  int dv = n / 1000 + (n % 1000 != 0);
  cout << 1000 * dv - n << '\n';
  return 0;
}

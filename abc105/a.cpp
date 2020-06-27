#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int n, k;
  cin >> n >> k;
  if (n % k == 0) {
    cout << 0 << '\n';
  } else {
    cout << 1 << '\n';
  }
  return 0;
}

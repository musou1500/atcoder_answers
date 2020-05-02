#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  long long n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    cout << i << ' ' << (n - i + 1) << '\n';
  }
  return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= m; ++i) {
    int j = n - i + 1;
    if (n % 2 == 0 && i > n / 4) {
      j--;
    }

    cout << i << ' ' << j << '\n';
  }
  return 0;
}

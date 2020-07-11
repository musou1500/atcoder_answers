#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;

  vector<int> cnts(10001, 0);
  for (int i = 1; i <= 100; ++i) {
    for (int j = 1; j < 101; ++j) {
      for (int k = 1; k < 101; ++k) {
        int a = i * i + j * j + k * k;
        a += (i * j) + (j * k) + (i * k);
        if (a >= cnts.size()) {
          continue;
        }

        cnts[a]++;
      }
    }
  }

  for (int i = 1; i <= n; ++i) {
    cout << cnts[i] << '\n';
  }

  return 0;
}

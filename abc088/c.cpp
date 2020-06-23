#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  array<array<int, 3>, 3> c;
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      cin >> c[i][j];
    }
  }

  bool ans = false;
  for (int a1 = 0; a1 <= 100 && !ans; ++a1) {
    array<int, 3> va, vb;
    va[0] = a1;
    vb[0] = c[0][0] - va[0];
    vb[1] = c[0][1] - va[0];
    vb[2] = c[0][2] - va[0];
    va[1] = c[1][0] - vb[0];
    va[2] = c[2][0] - vb[0];

    bool ok = true;
    for (int i = 0; i < 3 && ok; ++i) {
      for (int j = 0; j < 3 && ok; ++j) {
        if (c[i][j] == va[i] + vb[j]) {
          continue;
        }

        ok = false;
      }
    }

    if (ok) {
      ans = ok;
    }
  }

  cout << (ans ? "Yes" : "No") << '\n';
  return 0;
}

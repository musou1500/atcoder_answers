#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int n, c;
  cin >> n >> c;

  vector<vector<int>> vd(c, vector<int>(c));
  for (int i = 0; i < c; ++i) {
    for (int j = 0; j < c; ++j) {
      cin >> vd[i][j];
    }
  }

  // mod % 3がmで，色がcのマスの数: vm[m][c]
  vector<vector<int>> vm(3, vector<int>(c, 0));
  vector<vector<int>> vc(n, vector<int>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int c;
      cin >> c;
      c--;
      vc[i][j] = c;
      vm[(i + j + 2) % 3][c]++;
    }
  }

  int ans = -1;
  for (int i = 0; i < c; ++i) {
    for (int j = 0; j < c; ++j) {
      if (i == j) {
        continue;
      }

      for (int k = 0; k < c; ++k) {
        if (j == k || i == k) {
          continue;
        }

        // mod%3=0,1,2にそれぞれi, j, kを割り当てる
        // 元の色がl
        int d = 0;
        for (int l = 0; l < c; ++l) {
          d += vm[0][l] * vd[l][i];
          d += vm[1][l] * vd[l][j];
          d += vm[2][l] * vd[l][k];
        }

        if (ans < 0 || d < ans) {
          ans = d;
        }
      }
    }
  }

  cout << ans << '\n';

  return 0;
}

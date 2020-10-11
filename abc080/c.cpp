#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;
  vector<int> vf(n, 0);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 10; ++j) {
      int f;
      cin >> f;
      if (f == 1) {
        vf[i] |= (1 << j);
      }
    }
  }

  vector<vector<int>> vp(n, vector<int>(11));
  for (int i = 0; i < vp.size(); ++i) {
    for (int j = 0; j < vp[i].size(); ++j) {
      cin >> vp[i][j];
    }
  }

  int ans;
  for (int i = 1; i < (1 << 10); ++i) {
    int pt = 0;
    for (int j = 0; j < vf.size(); ++j) {
      int cnt = bitset<16>(i & vf[j]).count();
      pt += vp[j][cnt];
    }

    if (i == 1 || ans < pt) {
      ans = pt;
    }
  }

  cout << ans << '\n';
  return 0;
}

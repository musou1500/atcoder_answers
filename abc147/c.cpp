#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

bool judge(int bit, vector<vector<pair<int, int>>> &v) {
  for (int i = 0; i < v.size(); i++) {
    if (!(bit & (1 << i))) {
      continue;
    }
    
    // その人の証言をそれぞれ確認する
    for (auto &xy : v[i]) {
      int x = xy.first;
      int y = xy.second;
      if (y == 1 && !(bit & (1 << x))) {
        return false;
      }

      if (y == 0 && (bit & (1 << x))) {
        return false;
      }
    }
  }

  return true;
}

int main(int argc, const char *argv[])
{
  int n;
  cin >> n;
  vector<vector<pair<int, int>>> v(n);
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    v[i].resize(a);
    for (int j = 0; j < a; j++) {
      cin >> v[i][j].first >> v[i][j].second;
      --v[i][j].first;
    }
  }

  int res = 0;
  for (int bit = 0; bit < (1 << n); bit++) {
    if (judge(bit, v)) {
      int cnt = 0;
      for (int i = 0; i < n; i++) {
        if (bit & (1 << i)) {
          cnt++;
        }
      }

      res = max(res, cnt);
    }
  }

  cout << res << "\n";
  return 0;
}

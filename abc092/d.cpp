#include <bits/stdc++.h>

using namespace std;

vector<string> solve(int h, int w, int pat1, int pat2) {
  vector<vector<string>> pat_s{{
                                   "####",
                                   "...#",
                                   "...#",
                                   "...#",
                               },
                               {
                                   "####",
                                   "...#",
                                   ".#.#",
                                   "...#",
                               },
                               {
                                   "####",
                                   "####",
                                   "####",
                                   "####",
                               }};

  int pat3 = h * w - (pat1 + pat2);

  vector<vector<int>> pat(h / 4, vector<int>(w / 4));

  int cnt = 0;
  for (int i = 0; i < pat.size(); ++i) {
    for (int j = 0; j < pat[i].size(); ++j, cnt++) {
      if (cnt < pat1) {
        pat[i][j] = 0;
      } else if (cnt < pat1 + pat2) {
        pat[i][j] = 1;
      } else {
        pat[i][j] = 2;
      }
    }
  }

  vector<string> res;
  for (int i = 0; i < pat.size(); ++i) {
    for (int j = 0; j < 4; ++j) {
      string r = "";
      for (int k = 0; k < pat[i].size(); ++k) {
        r += pat_s[pat[i][k]][j];
      }
      res.push_back(r);
    }
  }

  return res;
}

int main(int argc, const char *argv[]) {
  int a, b;
  cin >> a >> b;
  bool reversed = a < b;
  if (reversed) {
    swap(a, b);
  }

  int h = 100, w = 100;
  cout << h << ' ' << w << '\n';

  b--;
  int pat1 = a - b, pat2 = b;
  vector<string> ans = solve(h, w, pat1, pat2);
  for (auto &s : ans) {
    for (int i = 0; i < s.size(); ++i) {
      if (!reversed) {
        cout << s[i];
      } else {
        cout << (s[i] == '.' ? '#' : '.');
      }
    }

    cout << '\n';
  }
  return 0;
}

#include <bits/stdc++.h>

using namespace std;

int solve(string &s, vector<vector<int>> &memo, int offset, bool flag) {
  int d = *(s.begin() + offset) - '0';
  if (offset == 0) {
    return flag ? 11 - d : d;
  }

  if (memo[offset][flag] < 0) {
    int res1 = solve(s, memo, offset - 1, false);
    int res2 = solve(s, memo, offset - 1, true);
    if (flag) {
      memo[offset][flag] = min(res1 + 11 - d, res2 + 9 - d);
    } else {
      memo[offset][flag] = min(res1, res2) + d;
    }
  }

  return memo[offset][flag];
}

int main(int argc, const char *argv[]) {
  string s;
  cin >> s;

  vector<vector<int>> memo(s.size(), vector<int>(2, -1));
  cout << min({solve(s, memo, s.size() - 1, false),
               solve(s, memo, s.size() - 1, true)})
       << '\n';
  return 0;
}

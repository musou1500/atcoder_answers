#include <bits/stdc++.h>

using namespace std;

int p_offset = 8150;

bool solve(vector<int> &va, int offset, int p, vector<vector<int>> &memo) {
  if (offset == va.size()) {
    return p == 0;
  }

  if (memo[offset][p + p_offset] == -1) {
    bool ans1, ans2;
    ans1 = solve(va, offset + 1, p - va[offset], memo);
    ans2 = solve(va, offset + 1, p + va[offset], memo);
    memo[offset][p + p_offset] = ans1 || ans2;
  }

  return memo[offset][p + p_offset];
}

int main(int argc, const char *argv[]) {
  string s;
  int x, y;
  cin >> s >> x >> y;

  s += 'T';

  int cnt = 0;
  bool is_x = true, skip = true;
  vector<int> x_mov, y_mov;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == 'F') {
      cnt++;
      continue;
    }

    if (is_x) {
      x_mov.push_back(cnt);
    } else {
      y_mov.push_back(cnt);
    }

    is_x = !is_x;
    cnt = 0;
  }

  vector<vector<int>> memo1(x_mov.size() + 1, vector<int>(p_offset * 2, -1)),
      memo2(y_mov.size() + 1, vector<int>(p_offset * 2, -1));
  bool ans_x, ans_y;

  ans_x = solve(x_mov, 1, x - x_mov.front(), memo1);
  ans_y = solve(y_mov, 0, y, memo2);

  if (ans_x && ans_y) {
    cout << "Yes" << '\n';
  } else {
    cout << "No" << '\n';
  }

  return 0;
}


#include <bits/stdc++.h>

using namespace std;

int solve(const vector<vector<int>> &v_positions,
          const vector<vector<int>> &h_positions, const pair<int, int> &pos) {
  int pos_x = pos.first, pos_y = pos.second, ans = 0;
  const vector<int> &v_pos = v_positions[pos_x], &h_pos = h_positions[pos_y];

  // up, down, left, right
  ans +=
      pos_y - *lower_bound(v_pos.rbegin(), v_pos.rend(), pos_y, greater<int>());
  ans += *lower_bound(v_pos.begin(), v_pos.end(), pos_y) - pos_y;
  ans +=
      pos_x - *lower_bound(h_pos.rbegin(), h_pos.rend(), pos_x, greater<int>());
  ans += *lower_bound(h_pos.begin(), h_pos.end(), pos_x) - pos_x;

  return max(0, ans - 3);
}

int main(int argc, const char *argv[]) {
  int h, w;
  cin >> h >> w;

  vector<vector<int>> v_positions(w), h_positions(h);
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      char ch;
      cin >> ch;
      if (ch == '#') {
        v_positions[j].push_back(i);
        h_positions[i].push_back(j);
      }
    }
  }

  for (int i = 0; i < h; ++i) {
    h_positions[i].push_back(-1);
    h_positions[i].push_back(w);
    sort(h_positions[i].begin(), h_positions[i].end());
  }

  for (int i = 0; i < w; ++i) {
    v_positions[i].push_back(-1);
    v_positions[i].push_back(h);
    sort(v_positions[i].begin(), v_positions[i].end());
  }

  int ans = 0;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      ans = max(ans, solve(v_positions, h_positions, {j, i}));
    }
  }

  cout << ans << '\n';
  return 0;
}


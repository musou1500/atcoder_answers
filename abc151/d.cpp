#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

struct Vec2 {
  int x;
  int y;
};

int max_dist(vector<vector<char>> &m, Vec2 &msize, Vec2 src) {
  if (m[src.y][src.x] == '#') {
    return -1;
  }

  vector<vector<bool>> visited(msize.y, vector<bool>(msize.x, false));
  queue<pair<Vec2, int>> q;
  q.push({{src.x, src.y}, 0});

  int ans = -1;
  while (!q.empty()) {
    auto pos = q.front().first;
    auto depth = q.front().second;
    q.pop();

    if (visited[pos.y][pos.x]) {
      continue;
    }
    visited[pos.y][pos.x] = true;
    ans = max(ans, depth);

    // up, down, left, right
    if (pos.y > 0 && m[pos.y - 1][pos.x] == '.') {
      q.push({{pos.x, pos.y - 1}, depth + 1});
    }
    if (pos.y < m.size() - 1 && m[pos.y + 1][pos.x] == '.') {
      q.push({{pos.x, pos.y + 1}, depth + 1});
    }
    if (pos.x > 0 && m[pos.y][pos.x - 1] == '.') {
      q.push({{pos.x - 1, pos.y}, depth + 1});
    }
    if (pos.x < m[0].size() - 1 && m[pos.y][pos.x + 1] == '.') {
      q.push({{pos.x + 1, pos.y}, depth + 1});
    }
  }

  return ans;
}

int main(int argc, const char *argv[]) {
  int h, w;
  cin >> h >> w;

  vector<vector<char>> m(h, vector<char>(w));
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> m[i][j];
    }
  }

  int ans = 0;
  Vec2 msize{w, h};
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      ans = max(ans, max_dist(m, msize, {j, i}));
    }
  }

  cout << ans << "\n";

  return 0;
}

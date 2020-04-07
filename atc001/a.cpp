#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(int argc, const char *argv[]) {
  int h, w;
  cin >> h >> w;

  vector<vector<char>> m(h, vector<char>(w));
  vector<vector<bool>> visited(h, vector<bool>(w, false));
  stack<pair<int, int>> st;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> m[i][j];
      if (m[i][j] == 's') {
        st.push({j, i});
      }
    }
  }

  bool ans = false;
  while (!st.empty()) {
    int x = st.top().first, y = st.top().second;
    st.pop();
    if (visited[y][x] || m[y][x] == '#') {
      continue;
    }

    if (m[y][x] == 'g') {
      ans = true;
      break;
    }

    visited[y][x] = true;

    // up, down, left, right
    if (y > 0) {
      st.push({x, y - 1});
    }

    if (y < h - 1) {
      st.push({x, y + 1});
    }

    if (x > 0) {
      st.push({x - 1, y});
    }

    if (x < w - 1) {
      st.push({x + 1, y});
    }
  }

  cout << (ans ? "Yes\n" : "No\n");
  return 0;
}

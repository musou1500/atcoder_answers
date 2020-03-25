#include <iostream>
#include <queue>
#include <utility>

using namespace std;
using Pos = pair<int, int>;

int minpath(int r, int c, Pos &start, Pos& goal, vector<vector<char>> &m) {
  queue<Pos> q;
  vector<vector<int>> minpaths(r, vector<int>(c, -1));
  q.push(start);
  minpaths[start.second][start.first] = 0;

  while (!q.empty()) {
    auto &pos = q.front();
    Pos left{pos.first - 1, pos.second};
    Pos right{pos.first + 1, pos.second};
    Pos up{pos.first, pos.second - 1};
    Pos down{pos.first, pos.second + 1};
    for (auto &neighbor : {left, right, up, down}) {
      if (m[neighbor.second][neighbor.first] == '#'
          || minpaths[neighbor.second][neighbor.first] != -1) {
        continue;
      }

      minpaths[neighbor.second][neighbor.first] = minpaths[pos.second][pos.first] + 1;
      q.push(neighbor);
    }

    q.pop();
  }

  return minpaths[goal.second][goal.first];
}

int main(int argc, const char *argv[])
{
  Pos start, goal;
  int r, c;
  cin >> r >> c;
  cin >> start.second >> start.first;
  cin >> goal.second >> goal.first;
  start.first--;
  start.second--;
  goal.first--;
  goal.second--;

  vector<vector<char>> m(r, vector<char>(c));
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> m[i][j];
    }
  }

  cout << minpath(r, c, start, goal, m) << "\n";
  return 0;
}

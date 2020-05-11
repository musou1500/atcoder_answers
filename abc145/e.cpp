#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int solve(vector<pair<int, int>> &foods, int t, vector<vector<int>> &memo,
          int offset = 0) {
  if (t <= 0 || offset == foods.size()) {
    return 0;
  }

  if (memo[t][offset] < 0) {
    auto &f = foods[offset];
    memo[t][offset] =
        max(solve(foods, t, memo, offset + 1),
            solve(foods, t - f.first, memo, offset + 1) + f.second);
  }

  return memo[t][offset];
}

int main(int argc, const char *argv[]) {
  int n, t;
  cin >> n >> t;

  vector<pair<int, int>> foods(n);
  for (auto &f : foods) {
    cin >> f.first >> f.second;
  }

  sort(foods.begin(), foods.end());

  vector<vector<int>> memo(t + 1, vector<int>(n + 1, -1));
  cout << solve(foods, t, memo) << '\n';
  return 0;
}

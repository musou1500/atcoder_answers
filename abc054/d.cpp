#include <bits/stdc++.h>

using namespace std;

int solve(vector<array<int, 3>> vmed, int a, int b, int offset,
          vector<vector<vector<int>>> &memo) {
  if (offset == vmed.size()) {
    return a == 0 && b == 0 ? 0 : -1;
  }

  if (a < 0 || b < 0) {
    return -1;
  }

  if (memo[a][b][offset] == -2) {
    auto &med = vmed[offset];
    int ans1 = solve(vmed, a, b, offset + 1, memo);
    int ans2 = solve(vmed, a - med[0], b - med[1], offset + 1, memo);
    if (ans2 >= 0) {
      ans2 += med[2];
    }

    if (ans1 >= 0 && ans2 >= 0) {
      memo[a][b][offset] = min(ans1, ans2);
    } else {
      memo[a][b][offset] = ans1 < 0 ? ans2 : ans1;
    }
  }

  return memo[a][b][offset];
}

int main(int argc, const char *argv[]) {
  int n, ma, mb;
  cin >> n >> ma >> mb;
  vector<array<int, 3>> vmed(n);
  for (auto &med : vmed) {
    cin >> med[0] >> med[1] >> med[2];
  }

  vector<vector<vector<int>>> memo(
      500, vector<vector<int>>(500, vector<int>(n + 1, -2)));

  int ans = -1;
  for (int i = 1; i <= 400 && max(ma, mb) * i <= 400; ++i) {
    int res = solve(vmed, ma * i, mb * i, 0, memo);
    if (res != -1 && (ans < 0 || res < ans)) {
      ans = res;
    }
  }

  cout << ans << '\n';
  return 0;
}

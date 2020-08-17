#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll solve(vector<vector<ll>> &pts, vector<vector<vector<ll>>> &memo, int r = 0,
         int c = 0, int cnt = 0) {
  if (r >= pts.size() || c >= pts.front().size()) {
    return 0;
  }

  if (memo[r][c][cnt] < 0) {
    ll v = pts[r][c];
    if (cnt >= 3) {
      memo[r][c][cnt] =
          max({solve(pts, memo, r + 1, c, 0), solve(pts, memo, r, c + 1, cnt)});
    } else {
      memo[r][c][cnt] =
          max({v + solve(pts, memo, r + 1, c, 0), solve(pts, memo, r + 1, c, 0),
               v + solve(pts, memo, r, c + 1, cnt + (v > 0)),
               solve(pts, memo, r, c + 1, cnt)});
    }
  }

  return memo[r][c][cnt];
}

int main(int argc, const char *argv[]) {
  int r, c, k;
  cin >> r >> c >> k;
  vector<vector<ll>> pts(r, vector<ll>(c, 0));
  for (int i = 0; i < k; ++i) {
    int r, c;
    ll v;
    cin >> r >> c >> v;
    r--;
    c--;
    pts[r][c] = v;
  }

  vector<vector<vector<ll>>> memo(r + 1, vector(c + 1, vector(4, -1ll)));
  cout << solve(pts, memo) << '\n';
  return 0;
}

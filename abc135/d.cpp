#include <iostream>
#include <string>
#include <vector>

using namespace std;

// sのoffset文字目まで決まっているとき，
// 13で割って5余る数が何通りあるか
const int md = 1e9 + 7;

using ll = long long;

ll solve(string &s, vector<vector<ll>> &memo, ll offset = 0, ll mod = 0) {
  if (offset == s.size()) {
    return mod == 5 ? 1 : 0;
  }

  if (memo[offset][mod] < 0) {
    if (s[offset] != '?') {
      ll d = s[offset] - '0';
      memo[offset][mod] = solve(s, memo, offset + 1, (mod * 10 + d) % 13) % md;
    } else {
      ll ans = 0;
      for (int i = 0; i < 10; ++i) {
        ans += solve(s, memo, offset + 1, (mod * 10 + i) % 13) % md;
      }

      memo[offset][mod] = ans % md;
    }
  }

  return memo[offset][mod];
}

int main(int argc, const char *argv[]) {
  string s;
  cin >> s;

  vector<vector<ll>> memo(s.size(), vector<ll>(13, -1));
  cout << solve(s, memo) << '\n';
  return 0;
}

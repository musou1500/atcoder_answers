#include <bits/stdc++.h>
#include <ios>

using namespace std;

const int md = 1e9 + 7;
using ll = long long;

ll solve(string &s, vector<vector<ll>> &memo, int offset = 0,
         bool is_less = false) {
  if (s.size() == offset) {
    return 1;
  }

  if (memo[offset][is_less] < 0) {
    char ch = s[offset];
    ll ans = 0;
    ans = (ans + solve(s, memo, offset + 1, is_less || ch == '1')) % md;
    if (ch == '1' || is_less) {
      ll res = (solve(s, memo, offset + 1, is_less) * 2) % md;
      ans = (ans + res) % md;
    }

    memo[offset][is_less] = ans % md;
  }

  return memo[offset][is_less];
}

int main(int argc, const char *argv[]) {
  string s;
  cin >> s;

  vector<vector<ll>> memo(s.size(), vector<ll>(2, -1));
  cout << solve(s, memo) << '\n';
  return 0;
}

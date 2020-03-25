#include <iostream>
#include <string>
#include <vector>

using namespace std;
using Memo = vector<vector<vector<int>>>;
const int mod = 1e9 + 7;

int solve(const string &s, int d, Memo &memo, bool is_less = false, int offset = 0, int acc = 0) {
  if (offset == s.size()) return acc == 0 ? 1 : 0;
  if (memo[is_less][offset][acc] < 0) {
    int digit = s[offset] - '0';
    int ans = 0;
    for (int i = 0; i <= (is_less ? 9 : digit); i++) {
      ans += solve(s, d, memo, is_less || i < digit, offset + 1, (acc + i) % d);
      ans %= mod;
    }

    memo[is_less][offset][acc] = ans;
  }

  return memo[is_less][offset][acc];
}

int main(int argc, const char *argv[])
{
  int d;
  string s;
  cin >> d >> s;
  Memo memo(2, vector<vector<int>>(s.size(), vector<int>(d, -1)));
  cout << solve(s, d, memo) - 1 << "\n";
  return 0;
}


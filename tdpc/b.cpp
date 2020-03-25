#include <iostream>
#include <vector>

using namespace std;
using Memo = vector<vector<int>>;

int solve(
    vector<int> &l_nums,
    vector<int> &r_nums,
    Memo &memo,
    int l = 0,
    int r = 0)
{
  if (l == l_nums.size() && r == r_nums.size()) return 0;
  if (memo[l][r] < 0) {
    bool parity = (l + r) % 2 == 0;
    int l_max = 0, r_max = 0;
    if (l < l_nums.size()) {
      l_max = solve(l_nums, r_nums, memo, l + 1, r) + (parity ? l_nums[l] : 0);
    }

    if (r < r_nums.size()) {
      r_max = solve(l_nums, r_nums, memo, l, r + 1) + (parity ? r_nums[r] : 0);
    }

    int res = max(l_max, r_max);
    if (l < l_nums.size() && r < r_nums.size() && !parity) {
      res = min(l_max, r_max);
    }

    memo[l][r] = res;
  }

  return memo[l][r];
}

int main(int argc, const char *argv[])
{
  int a, b;
  cin >> a >> b;
  vector<int> l_nums(a);
  vector<int> r_nums(b);
  for (int i = 0; i < a; i++) cin >> l_nums[i];
  for (int i = 0; i < b; i++) cin >> r_nums[i];

  Memo memo(a + 1, vector<int>(b + 1, -1));
  cout << solve(l_nums, r_nums, memo) << "\n";
  return 0;
}

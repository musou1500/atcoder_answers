#include <bits/stdc++.h>

using namespace std;

int solve(int n, vector<int> &vn, vector<int> &memo) {
  if (n < 6) {
    return n;
  }

  if (memo[n] < 0) {
    int ans = n;
    for (auto nn : vn) {
      if (n < nn) {
        break;
      }

      ans = min(ans, solve(n - nn, vn, memo) + 1);
    }

    memo[n] = ans;
  }

  return memo[n];
}

int main(int argc, const char *argv[]) {
  int n = 0;
  cin >> n;

  vector<int> vn;
  for (int pow6 = 6; pow6 <= n; pow6 *= 6) {
    vn.push_back(pow6);
  }

  for (int pow9 = 9; pow9 <= n; pow9 *= 9) {
    vn.push_back(pow9);
  }

  sort(vn.begin(), vn.end());

  vector<int> memo(n + 1, -1);
  cout << solve(n, vn, memo) << '\n';
  return 0;
}

#include <bits/stdc++.h>

using namespace std;

const int md = 1e9 + 7;

long long solve(vector<int> &va, int n, vector<long long> &memo, int cur = 0) {
  if (cur == n) {
    return 1;
  } else if (cur > n) {
    return 0;
  }

  if (memo[cur] < 0) {
    if (binary_search(va.begin(), va.end(), cur)) {
      memo[cur] = 0;
    } else {
      memo[cur] =
          (solve(va, n, memo, cur + 1) + solve(va, n, memo, cur + 2)) % md;
    }
  }

  return memo[cur];
}

int main(int argc, const char *argv[]) {
  int n, m;
  cin >> n >> m;

  vector<int> va(m);
  for (int i = 0; i < m; ++i) {
    cin >> va[i];
  }

  sort(va.begin(), va.end());

  vector<long long> memo(n, -1);
  cout << solve(va, n, memo) << '\n';
  return 0;
}

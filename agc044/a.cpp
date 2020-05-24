#include <bits/stdc++.h>

using namespace std;

using ull = unsigned long long;

ull solve(map<ull, ull> &memo, ull n, array<ull, 4> &costs) {
  if (n == 0) {
    return 0;
  } else if (n == 1) {
    return costs.back();
  }

  if (memo.count(n) > 0) {
    return memo[n];
  }

  array<ull, 3> d{2, 3, 5};

  ull ans = costs[3] * n;
  for (int i = 0; i <= 2; ++i) {
    ull k = 0;
    while ((n + k) % d[i] != 0) {
      k++;
    }

    ans = min(ans,
              solve(memo, (n + k) / d[i], costs) + costs[i] + k * costs.back());
    k = 0;
    while ((n - k) % d[i] != 0) {
      k++;
    }

    ans = min(ans,
              solve(memo, (n - k) / d[i], costs) + costs[i] + k * costs.back());
  }

  return memo[n] = ans;
}

int main(int argc, const char *argv[]) {
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    ull n;
    array<ull, 4> costs;

    cin >> n;
    for (int i = 0; i < costs.size(); ++i) {
      cin >> costs[i];
    }

    map<ull, ull> memo;
    ull ans = solve(memo, n, costs);
    cout << ans << '\n';
  }

  return 0;
}

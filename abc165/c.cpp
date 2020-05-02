#include <bits/stdc++.h>

using namespace std;

bool next_va(vector<int> &va, int m) {
  int i = va.size() - 1;
  while (i >= 0 && va[i] >= m) {
    i--;
  }

  if (i < 0) {
    return false;
  }

  va[i]++;
  fill(va.begin() + i, va.end(), va[i]);
  return true;
}

int calc_rank(vector<int> &va, vector<array<int, 4>> &requirements) {
  int ans = 0;
  for (auto [a, b, c, d] : requirements) {
    if (va[b] - va[a] == c) {
      ans += d;
    }
  }

  return ans;
}

int main(int argc, const char *argv[]) {
  int n, m, q;
  cin >> n >> m >> q;

  vector<array<int, 4>> requirements(q);
  for (auto &r : requirements) {
    cin >> r[0] >> r[1] >> r[2] >> r[3];
    r[0]--;
    r[1]--;
  }

  vector<int> va(n, 1);
  int ans = 0;
  do {
    ans = max(ans, calc_rank(va, requirements));
  } while (next_va(va, m));

  cout << ans << '\n';
  return 0;
}

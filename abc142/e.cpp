#include <bitset>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int solve(vector<pair<int, int>> &keys, int n, vector<vector<int>> &memo,
          int s = 0, int offset = 0) {
  if (offset == keys.size()) {
    return bitset<32>(s).count() == n ? 0 : -1;
  }

  if (memo[s][offset] < -1) {
    int a = solve(keys, n, memo, s | keys[offset].second, offset + 1);
    int b = solve(keys, n, memo, s, offset + 1);
    if (a >= 0) {
      a += keys[offset].first;
    }
    memo[s][offset] = (a < 0 || b < 0) ? max(a, b) : min(a, b);
  }

  return memo[s][offset];
}

int main(int argc, const char *argv[]) {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> keys(m);
  for (auto &key : keys) {
    int b;
    key.second = 0;
    cin >> key.first >> b;
    for (int i = 0; i < b; i++) {
      int c;
      cin >> c;
      c--;
      key.second |= (1 << c);
    }
  }

  vector<vector<int>> memo(pow(2, n), vector<int>(m + 1, -2));
  cout << solve(keys, n, memo) << '\n';
  return 0;
}

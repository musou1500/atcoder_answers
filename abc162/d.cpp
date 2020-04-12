#include <algorithm>
#include <array>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

ll choose(vector<int> &ch_pos, int i, int j) {
  auto it = upper_bound(ch_pos.begin(), ch_pos.end(), j);
  ll ans = distance(it, ch_pos.end());
  bool found = binary_search(it, ch_pos.end(), 2 * j - i);
  if (found) {
    ans = max(0ll, ans - 1);
  }

  return ans;
}

int main() {
  int n;
  string s;
  cin >> n >> s;

  array<vector<int>, 256> ch_pos;
  for (int i = 0; i < n; i++) {
    ch_pos[s[i]].push_back(i);
  }

  array<char, 3> kinds{'B', 'G', 'R'};
  ll ans = 0;
  do {
    for (int i : ch_pos[kinds[0]]) {
      for (int j : ch_pos[kinds[1]]) {
        if (i < j) {
          ans += choose(ch_pos[kinds[2]], i, j);
        }
      }
    }
  } while (next_permutation(kinds.begin(), kinds.end()));
  cout << ans << '\n';
  return 0;
}


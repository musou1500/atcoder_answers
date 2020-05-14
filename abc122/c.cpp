#include <bits/stdc++.h>
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

int solve(vector<int> &vpos, int l, int r) {
  auto lb_it = lower_bound(vpos.begin(), vpos.end(), l);
  auto ub_it = upper_bound(vpos.begin(), vpos.end(), r);
  int ans = distance(lb_it, ub_it);
  if (binary_search(vpos.begin(), vpos.end(), r)) {
    ans--;
  }

  return ans;
}

int main(int argc, const char *argv[]) {
  int n, q;
  string s;
  cin >> n >> q >> s;

  vector<pair<int, int>> qs(q);
  for (auto &q : qs) {
    cin >> q.first >> q.second;
    q.first--;
    q.second--;
  }

  vector<int> vpos;
  for (int i = 1; i < s.size(); i++) {
    if (s[i - 1] == 'A' && s[i] == 'C') {
      vpos.push_back(i - 1);
    }
  }

  for (auto q : qs) {
    cout << solve(vpos, q.first, q.second) << '\n';
  }

  return 0;
}

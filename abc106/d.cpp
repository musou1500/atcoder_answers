#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int n, m, q;
  cin >> n >> m >> q;

  vector<vector<int>> cnt(n, vector<int>(n, 0));
  for (int i = 0; i < m; ++i) {
    int l, r;
    cin >> l >> r;
    l--;
    r--;
    cnt[l][r]++;
  }

  vector<vector<int>> psum(n);
  for (int i = 0; i < n; ++i) {
    psum[i].push_back(0);
    partial_sum(cnt[i].begin(), cnt[i].end(), back_inserter(psum[i]));
  }

  vector<int> ans;
  for (int i = 0; i < q; ++i) {
    int l, r;
    cin >> l >> r;
    l--;
    r--;

    int a = 0;
    for (int j = l; j <= r; ++j) {
      a += psum[j][r + 1] - psum[j][l];
    }

    ans.push_back(a);
  }

  for (int i = 0; i < ans.size(); ++i) {
    cout << ans[i] << '\n';
  }

  return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;
  string s;
  cin >> s;

  array<vector<int>, 4> cnts;
  array<char, 4> chs{'A', 'G', 'C', 'T'};
  for (int i = 0; i < chs.size(); ++i) {
    auto c = chs[i];
    auto &cnt = cnts[i];
    cnt.push_back(0);
    for (int j = 0; j < n; j++) {
      cnt.push_back(cnt.back());
      if (s[j] == c) {
        cnt[cnt.size() - 1]++;
      }
    }
  }

  auto cnt = [](int l, int r, vector<int> &psum) { return psum[r] - psum[l]; };
  auto solve = [&](int l, int r) {
    int a_cnt = cnt(l, r, cnts[0]);
    int g_cnt = cnt(l, r, cnts[1]);
    int c_cnt = cnt(l, r, cnts[2]);
    int t_cnt = cnt(l, r, cnts[3]);
    if (r - l <= 1) {
      return 0;
    }

    if (a_cnt == t_cnt && c_cnt == g_cnt) {
      return 1;
    } else {
      return 0;
    }
  };
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      ans += solve(i, j);
    }
  }

  cout << ans << '\n';
  return 0;
}

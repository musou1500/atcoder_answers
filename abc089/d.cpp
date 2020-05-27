#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int h, w, d;
  cin >> h >> w >> d;

  vector<pair<int, int>> n_positions(h * w + 1);
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      int a;
      cin >> a;
      n_positions[a].first = i;
      n_positions[a].second = j;
    }
  }

  auto get_dist = [&](int a, int b) {
    auto &pos_a = n_positions[a];
    auto &pos_b = n_positions[b];
    return abs(pos_a.first - pos_b.first) + abs(pos_a.second - pos_b.second);
  };

  vector<vector<int>> dist_cache(d);
  for (int i = 0; i < d; i++) {
    auto &psums = dist_cache[i];
    psums.push_back(0);
    for (int j = i == 0 ? d * 2 : i + d; j <= h * w; j += d) {
      int dist = get_dist(j, j - d);
      psums.push_back(psums.back() + dist);
    }
  }

  int q;
  cin >> q;

  vector<int> ans;
  for (int i = 0; i < q; ++i) {
    int l, r;
    cin >> l >> r;

    int md_r = l % d;
    auto &psum = dist_cache[md_r];

    int l_idx = (l - md_r) / d;
    int r_idx = (r - md_r) / d;
    if (md_r == 0) {
      l_idx--;
      r_idx--;
    }

    ans.push_back(psum[r_idx] - psum[l_idx]);
  }

  for (int i = 0; i < ans.size(); ++i) {
    cout << ans[i] << '\n';
  }

  return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  //
  int h, w, m;
  cin >> h >> w >> m;

  vector<pair<int, int>> tgts(m);
  vector<int> cnt_row(h, 0), cnt_col(w, 0);
  for (int i = 0; i < m; ++i) {
    cin >> tgts[i].first >> tgts[i].second;
    tgts[i].first--;
    tgts[i].second--;
    cnt_row[tgts[i].first]++;
    cnt_col[tgts[i].second]++;
  }

  sort(tgts.begin(), tgts.end());

  int max_col = *max_element(cnt_col.begin(), cnt_col.end());
  int max_row = *max_element(cnt_row.begin(), cnt_row.end());

  int cnt1 = 0, cnt2 = 0;
  vector<int> vr, vc;
  for (int i = 0; i < cnt_row.size(); i++) {
    if (cnt_row[i] == max_row) {
      vr.push_back(i);
    }
  }

  for (int i = 0; i < cnt_col.size(); i++) {
    if (cnt_col[i] == max_col) {
      vc.push_back(i);
    }
  }

  for (auto r : vr) {
    for (auto c : vc) {
      auto p = make_pair(r, c);
      if (!binary_search(tgts.begin(), tgts.end(), p)) {
        cout << max_col + max_row << '\n';
        return 0;
      }
    }
  }

  cout << max_col + max_row - 1 << '\n';

  return 0;
}

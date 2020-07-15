#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;

  vector<pair<int, int>> vp1(n), vp2(n);
  for (auto &p : vp1) {
    cin >> p.first >> p.second;
  }

  for (auto &p : vp2) {
    cin >> p.first >> p.second;
  }

  vector<vector<int>> indeces(n);
  vector<int> ref_cnts(n, 0);
  for (int i = 0; i < n; i++) {
    auto [x1, y1] = vp1[i];
    for (int j = 0; j < n; j++) {
      auto [x2, y2] = vp2[j];
      if (x1 < x2 && y1 < y2) {
        ref_cnts[j]++;
        indeces[i].push_back(j);
      }
    }
  }

  for (int i = 0; i < indeces.size(); ++i) {
    sort(indeces[i].begin(), indeces[i].end(),
         [&](auto &a, auto &b) { return ref_cnts[a] < ref_cnts[b]; });
  }

  sort(indeces.begin(), indeces.end(),
       [](auto &a, auto &b) { return a.size() < b.size(); });

  vector<int> used(n, false);
  int ans = 0;
  for (int i = 0; i < indeces.size(); ++i) {
    for (int j = 0; j < indeces[i].size(); ++j) {
      if (!used[indeces[i][j]]) {
        used[indeces[i][j]] = true;
        ans++;
        break;
      }
    }
  }

  cout << ans << '\n';
}


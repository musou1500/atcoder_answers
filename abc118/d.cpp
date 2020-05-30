#include <bits/stdc++.h>
#include <algorithm>
#include <vector>

using namespace std;

string solve(vector<int> &va, int n) {}

int main(int argc, const char *argv[]) {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> va(m);
  vector<int> costs{2, 5, 5, 4, 5, 6, 3, 7, 6};
  for (int i = 0; i < m; ++i) {
    int a;
    cin >> a;
    va[i].first = costs[a - 1];
    va[i].second = a;
  }

  sort(va.begin(), va.end(), [](auto p1, auto p2) {
    return (p1.first != p2.first) ? p1.first < p2.first : p1.second > p2.second;
  });
  return 0;
}

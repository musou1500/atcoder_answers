#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int n, m;
  cin >> n >> m;

  vector<int> vx(m);
  for (int i = 0; i < m; ++i) {
    cin >> vx[i];
  }

  sort(vx.begin(), vx.end());
  n--;

  vector<int> dists(m - 1);
  for (int i = 0; i < m - 1; ++i) {
    dists[i] = abs(vx[i + 1] - vx[i]);
  }

  sort(dists.begin(), dists.end(), greater<int>());

  int sum = accumulate(dists.begin(), dists.end(), 0);
  for (int i = 0; i < min(n, static_cast<int>(dists.size())); ++i) {
    sum -= dists[i];
  }

  cout << sum << '\n';
  return 0;
}

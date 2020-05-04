#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  long long n, m;
  cin >> n >> m;

  vector<pair<long long, long long>> vab(n);
  for (auto &p : vab) {
    cin >> p.first >> p.second;
  }

  sort(vab.begin(), vab.end());
  long long ans = 0, cur = 0;
  while (m > 0) {
    long long cnt = min(m, vab[cur].second);
    ans += vab[cur].first * cnt;
    m -= cnt;
    cur++;
  }

  cout << ans << '\n';
  return 0;
}


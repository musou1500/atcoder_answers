#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int main(int argc, const char *argv[]) {
  int n, m;
  cin >> n;

  vector<string> vs(n);
  for (int i = 0; i < n; ++i) {
    cin >> vs[i];
  }

  cin >> m;
  vector<string> vt(m);
  for (int i = 0; i < m; ++i) {
    cin >> vt[i];
  }

  auto pt = [&](string &s) {
    int ans = 0;
    ans += count(vs.begin(), vs.end(), s);
    ans -= count(vt.begin(), vt.end(), s);
    return ans;
  };

  int ans = 0;
  for (int i = 0; i < vs.size(); ++i) {
    ans = max(ans, pt(vs[i]));
  }

  cout << ans << '\n';

  return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int n, l;
  cin >> n >> l;
  vector<string> vs(n);
  for (int i = 0; i < n; ++i) {
    cin >> vs[i];
  }

  sort(vs.begin(), vs.end());
  string ans;
  for (int i = 0; i < vs.size(); ++i) {
    ans += vs[i];
  }

  cout << ans << '\n';

  return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;

  map<int, int> cnts;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    cnts[a]++;
  }

  int ans = cnts.size();
  int even_cnt = 0;
  for (auto &p : cnts) {
    bool even = p.second % 2 == 0;
    p.second = even ? 2 : 1;
    even_cnt += even;
  }

  if (even_cnt % 2 == 0) {
    cout << ans << '\n';
  } else {
    cout << ans - 1 << '\n';
  }

  return 0;
}

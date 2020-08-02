#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;

  vector<char> vc(n);
  int r_cnt = 0, w_cnt = 0;
  for (int i = 0; i < n; ++i) {
    cin >> vc[i];
    if (vc[i] == 'R') {
      r_cnt++;
    } else {
      w_cnt++;
    }
  }

  int nw_cnt = 0, nr_cnt = 0;
  for (int i = 0; i < r_cnt; ++i) {
    if (vc[i] != 'R') {
      nw_cnt++;
    }
  }

  for (int i = 0; i < w_cnt; ++i) {
    if (vc[vc.size() - i - 1] != 'W') {
      nr_cnt++;
    }
  }

  cout << min(nw_cnt, nr_cnt) << '\n';
  return 0;
}

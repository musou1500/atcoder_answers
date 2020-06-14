#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int x, n;
  cin >> x >> n;
  set<int> vp;
  for (int i = 0; i < n; ++i) {
    int p;
    cin >> p;
    vp.insert(p);
  }

  int min_abs = -1, min_n = -1;
  for (int i = -100; i < 200; ++i) {
    if (vp.count(i) > 0) {
      continue;
    }

    int abs_n = abs(x - i);
    if (min_abs < 0 || min_abs > abs_n) {
      min_abs = abs_n;
      min_n = i;
    } else if (min_abs == abs_n && min_n > i) {
      min_n = i;
    }
  }

  cout << min_n << '\n';

  return 0;
}

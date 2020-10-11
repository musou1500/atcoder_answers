#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;

  vector<array<int, 3>> vt(n - 1);
  for (int i = 0; i < n - 1; ++i) {
    cin >> vt[i][0] >> vt[i][1] >> vt[i][2];
  }

  for (int i = 0; i < n - 1; ++i) {
    int cur = i, t = 0;
    while (cur != n - 1) {
      int next_t;

      // cur -> cur + 1
      int c, f, s;
      c = vt[cur][0];
      s = vt[cur][1];
      f = vt[cur][2];

      if (s >= t) {
        next_t = s + c;
      } else {
        next_t = t + (t % f) + c;
      }

      cur++;
      t = next_t;
    }

    cout << t << '\n';
  }

  cout << 0 << '\n';
  return 0;
}

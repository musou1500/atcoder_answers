#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;

  vector<bool> vd(n);
  for (int i = 0; i < n; ++i) {
    int d1, d2;
    cin >> d1 >> d2;
    vd[i] = d1 == d2;
  }

  bool ok = false;
  for (int i = 0; i < n - 2 && !ok; ++i) {
    ok = vd[i] && vd[i + 1] && vd[i + 2];
  }

  if (ok) {
    cout << "Yes" << '\n';
  } else {
    cout << "No" << '\n';
  }

  return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int h = 2, w = 3;
  vector<string> vs(h);
  for (int i = 0; i < h; ++i) {
    cin >> vs[i];
  }

  reverse(vs[0].begin(), vs[0].end());
  if (vs[0] == vs[1]) {
    cout << "YES" << '\n';
  } else {
    cout << "NO" << '\n';
  }

  return 0;
}

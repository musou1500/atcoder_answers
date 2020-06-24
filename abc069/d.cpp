#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int h, w, n, a;
  cin >> h >> w >> n;
  vector<int> va;
  for (int i = 0; i < n; ++i) {
    cin >> a;
    while (a--) va.push_back(i + 1);
  }

  for (int i = 0; i < h * w; ++i) {
    int r = i / w, c = i % w;
    cout << (r % 2 ? va[i] : va[(r + 1) * w - c - 1]);
    cout << (c == w - 1 ? '\n' : ' ');
  }

  return 0;
}

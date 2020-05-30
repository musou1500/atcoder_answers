#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int h1, h2, m1, m2, k;
  cin >> h1 >> m1 >> h2 >> m2 >> k;
  int dur = (h2 - h1) * 60;
  dur -= m1;
  dur += m2;

  cout << max(0, dur - k) << '\n';
  return 0;
}

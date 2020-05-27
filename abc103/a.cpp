#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  vector<int> va(3);
  for (int i = 0; i < 3; ++i) {
    cin >> va[i];
  }

  sort(va.begin(), va.end());

  int fst = va.front();
  int ans = 0;
  ans += abs(va[1] - fst);
  ans += abs(va[2] - va[1]);

  cout << ans << '\n';
  return 0;
}

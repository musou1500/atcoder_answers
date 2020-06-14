#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main(int argc, const char *argv[]) {
  vector<int> vx(5);
  int ans;
  for (int i = 0; i < 5; ++i) {
    cin >> vx[i];
    if (vx[i] == 0) {
      ans = i + 1;
    }
  }

  cout << ans << '\n';
  return 0;
}

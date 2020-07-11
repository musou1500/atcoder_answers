#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;
  vector<int> va(n);
  for (int i = 0; i < n; ++i) {
    cin >> va[i];
  }

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (va[i] % 2 == 1 && (i + 1) % 2 == 1) {
      ans++;
    }
  }

  cout << ans << '\n';
  return 0;
}

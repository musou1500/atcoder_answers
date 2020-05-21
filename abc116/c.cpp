#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;
  vector<int> vh(n);
  for (int i = 0; i < n; ++i) {
    cin >> vh[i];
  }

  int ans = 0;
  while (true) {
    int l = 0;
    while (l < vh.size() && vh[l] == 0) {
      l++;
    }

    if (l >= vh.size()) {
      break;
    }

    int r = l;
    while (r < vh.size() && vh[r] != 0) {
      vh[r]--;
      r++;
    }

    // [l, r)
    ans++;
  }

  cout << ans << '\n';

  return 0;
}

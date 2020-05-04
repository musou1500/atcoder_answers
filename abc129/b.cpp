#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;

  vector<int> vw(n);
  for (int i = 0; i < n; ++i) {
    cin >> vw[i];
  }

  int ans = -1;
  for (int i = 0; i < n; ++i) {
    int s1 = 0, s2 = 0, threshold = i;
    for (int j = 0; j < n; ++j) {
      if (j <= threshold) {
        s1 += vw[j];
      } else {
        s2 += vw[j];
      }
    }

    int diff = abs(s1 - s2);
    ans = ans < 0 ? diff : min(ans, diff);
  }

  cout << ans << '\n';
  return 0;
}

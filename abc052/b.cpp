#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int n;
  string s;
  cin >> n >> s;
  int x = 0, ans = 0;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == 'I') {
      x++;
    } else {
      x--;
    }

    ans = max(ans, x);
  }

  cout << ans << '\n';
  return 0;
}

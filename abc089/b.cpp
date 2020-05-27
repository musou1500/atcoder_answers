#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;

  string ans = "Three";
  for (int i = 0; i < n; ++i) {
    char c;
    cin >> c;
    if (c == 'Y') {
      ans = "Four";
      break;
    }
  }

  cout << ans << '\n';
  return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int k;
  cin >> k;
  string ans;
  string s = "ACL";
  for (int i = 0; i < k; ++i) {
    ans += s;
  }

  cout << ans << '\n';
  return 0;
}

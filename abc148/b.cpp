#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char *argv[]) {
  int n;
  string s, t, ans;
  cin >> n >> s >> t;
  for (int i = 0; i < n; i++) {
    ans += s[i];
    ans += t[i];
  }

  cout << ans << '\n';
  return 0;
}

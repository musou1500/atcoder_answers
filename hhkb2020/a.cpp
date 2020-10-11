#include <bits/stdc++.h>

#include <cctype>

using namespace std;

int main(int argc, const char *argv[]) {
  string s, t;
  cin >> s >> t;

  if (s == "N") {
    cout << t << '\n';
  } else {
    string ans;
    for (int i = 0; i < t.size(); ++i) {
      ans += toupper(t[i]);
    }
    cout << ans << '\n';
  }
  return 0;
}

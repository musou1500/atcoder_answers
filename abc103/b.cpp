#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  string s, t;
  cin >> s >> t;

  if (s == t) {
    cout << "Yes" << '\n';
    return 0;
  }

  bool ans = false;
  for (int i = 0; i < s.size(); ++i) {
    char last_ch = s.back();
    s = last_ch + s.substr(0, s.size() - 1);
    if (s == t) {
      ans = true;
      break;
    }
  }

  cout << (ans ? "Yes" : "No") << '\n';
  return 0;
}

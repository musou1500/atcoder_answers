#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  string s;
  cin >> s;

  bool ans = false;
  for (int i = 0; i < 2; ++i) {
    if (s[i] == s[i + 1] && s[i + 1] == s[i + 2]) {
      ans = true;
      break;
    }
  }

  cout << (ans ? "Yes" : "No") << '\n';
  return 0;
  return 0;
}

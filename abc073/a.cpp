#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  string s;
  cin >> s;
  bool ans = false;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == '9') {
      ans = true;
      break;
    }
  }

  cout << (ans ? "Yes" : "No") << '\n';
  return 0;
}

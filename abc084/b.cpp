#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int a, b;
  string s;
  cin >> a >> b >> s;

  bool ans = true;
  for (int i = 0; i < s.size(); ++i) {
    if (i == a && s[i] != '-') {
      ans = false;
      break;
    }

    if (i != a && (s[i] < '0' || s[i] > '9')) {
      ans = false;
      break;
    }
  }

  cout << (ans ? "Yes" : "No") << '\n';
  return 0;
}

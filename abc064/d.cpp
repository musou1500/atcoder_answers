#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;
  string s;
  cin >> s;

  string prefix = "";
  int st = 0, op = 0;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == ')') {
      if (st == 0) {
        prefix += "(";
      } else {
        st--;
      }
    } else {
      st++;
    }
  }

  string suffix = "";
  for (int i = 0; i < st; ++i) {
    suffix += ")";
  }

  cout << prefix + s + suffix << '\n';

  return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  string s, t;
  cin >> s >> t;
  if (t.size() - s.size() != 1) {
    cout << "No" << '\n';
    return 0;
  }

  for (int i = 0; i < s.size(); ++i) {
    if (s[i] != t[i]) {
      cout << "No" << '\n';
      return 0;
    }
  }

  cout << "Yes" << '\n';
  return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  string s;
  cin >> s;

  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == '?') {
      s[i] = 'D';
    }
  }

  cout << s << '\n';
  return 0;
}

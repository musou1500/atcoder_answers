#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  string s;
  cin >> s;
  set<char> chs;
  bool ans = true;
  for (int i = 0; i < s.size(); ++i) {
    if (chs.count(s[i]) > 0) {
      ans = false;
      break;
    }

    chs.insert(s[i]);
  }

  if (ans) {
    cout << "yes" << '\n';
  } else {
    cout << "no" << '\n';
  }

  return 0;
}

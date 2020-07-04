#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  string s;
  cin >> s;

  if (s.front() != 'A') {
    cout << "WA" << '\n';
    return 0;
  }

  int fst_c_idx = -1;
  for (int i = 2; i < s.size() - 1; ++i) {
    if (s[i] == 'C') {
      fst_c_idx = i;
      break;
    }
  }

  if (fst_c_idx < 0) {
    cout << "WA" << '\n';
    return 0;
  }

  bool ans = true;
  for (int i = 1; i < s.size(); ++i) {
    if (i == fst_c_idx) {
      continue;
    }

    if (s[i] >= 'A' && s[i] <= 'Z') {
      ans = false;
      break;
    }
  }

  cout << (ans ? "AC" : "WA") << '\n';
  return 0;
}

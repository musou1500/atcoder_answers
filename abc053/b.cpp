#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  string s;
  cin >> s;

  int fst_a = 0, last_z = 0;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == 'A') {
      fst_a = i;
      break;
    }
  }

  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == 'Z') {
      last_z = i;
    }
  }

  cout << last_z - fst_a + 1 << '\n';
  return 0;
}

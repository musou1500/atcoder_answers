#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  string s;
  long long k;
  cin >> s >> k;
  k--;

  long long fst_idx = s.size();
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] != '1') {
      fst_idx = i;
      break;
    }
  }

  if (k < fst_idx) {
    cout << 1 << '\n';
  } else {
    cout << s[fst_idx] << '\n';
  }
  return 0;
}

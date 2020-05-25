#include <bits/stdc++.h>

using namespace std;

int solve(string &s, int offset = 0, bool is_less = false, bool has3 = false,
          bool has5 = false, bool has7 = false) {
  if (offset == s.size()) {
    return has3 && has5 && has7;
  }

  vector<int> elms{0, 3, 5, 7};
  int d = s[offset] - '0';
  int ans = 0;
  for (int i = 0; i < elms.size(); ++i) {
    if (!is_less && d < elms[i]) {
      continue;
    }

    if ((has3 || has5 || has7) && elms[i] == 0) {
      continue;
    }

    ans += solve(s, offset + 1, is_less || (d > elms[i]), has3 || elms[i] == 3,
                 has5 || elms[i] == 5, has7 || elms[i] == 7);
  }

  return ans;
}

int main(int argc, const char *argv[]) {
  string s;
  cin >> s;

  cout << solve(s) << '\n';
  return 0;
}

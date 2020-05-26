#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  string s;
  int k;
  cin >> s >> k;

  vector<string> ans;
  for (int i = 0; i < k; ++i) {
    for (int j = 0; j < s.size() - i; ++j) {
      ans.push_back(s.substr(j, i + 1));
    }
  }

  sort(ans.begin(), ans.end());
  unique(ans.begin(), ans.end());

  cout << ans[k - 1] << '\n';
  return 0;
}


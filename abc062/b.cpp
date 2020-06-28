#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int h, w;
  cin >> h >> w;
  vector<string> ans;
  ans.push_back(string(w + 2, '#'));
  for (int i = 0; i < h; ++i) {
    string r, inner;
    cin >> inner;
    r = '#' + inner + '#';
    ans.push_back(r);
  }
  ans.push_back(string(w + 2, '#'));

  for (int i = 0; i < ans.size(); ++i) {
    cout << ans[i] << '\n';
  }
  return 0;
}

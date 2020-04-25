#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// s[i:], s[j:] が何文字目まで一致するか
// 0 <= i < j < |S|
int solve(string &s, vector<vector<int>> &memo, int i, int j) {
  if (i >= s.size() || j >= s.size() || s[i] != s[j]) {
    return 0;
  }

  if (memo[i][j] < 0) {
    memo[i][j] = min(j - i, solve(s, memo, i + 1, j + 1) + 1);
  }

  return memo[i][j];
}

int main(int argc, const char *argv[]) {
  int n;
  string s;
  cin >> n >> s;

  vector<vector<int>> memo(s.size(), vector<int>(s.size(), -1));
  int ans = 0;
  for (int i = 0; i < s.size() - 1; i++) {
    for (int j = i + 1; j < s.size(); j++) {
      ans = max(ans, solve(s, memo, i, j));
    }
  }

  cout << ans << '\n';
  return 0;
}

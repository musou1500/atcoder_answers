#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

int main(int argc, const char *argv[])
{
  int n;
  cin >> n;

  vector<vector<int>> memo(10, vector<int>(10, 0));
  for (int i = 1; i <= n; i++) {
    string s = to_string(i);
    memo[s.front() - '0'][s.back() - '0']++;
  }

  int ans = 0;
  for (int i = 1; i <= 9; i++) {
    for (int j = 1; j <= 9; j++) {
      ans += memo[i][j] * memo[j][i];
    }
  }

  cout << ans << "\n";
  return 0;
}

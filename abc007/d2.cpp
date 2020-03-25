#include <iostream>
#include <array>
#include <vector>
#include <string>

using namespace std;

long long solve(long long n) {
  string s = to_string(n);
  vector<array<array<long long, 2>, 2>> dp(s.size() + 1);
  
  // dp[i][j][k]
  // i: 決定した桁数
  // j: N未満確定か
  // k: 4，または9を含むか
  dp[0][0][0] = 1;
  for (int i = 0; i < s.size(); i++) {
    int d = s[i] - '0';
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 2; k++) {
        for (int l = 0; l <= (j == 1 ? 9 : d); l++) {
          dp[i + 1][j || (l < d)][k || l == 4 || l == 9] += dp[i][j][k];
        }
      }
    }
  }
  
  return dp[s.size()][0][1] + dp[s.size()][1][1];
}

int main(int argc, const char *argv[])
{
  long long a, b;
  cin >> a >> b;
  cout << solve(b) - solve(a - 1) << "\n";
  return 0;
}


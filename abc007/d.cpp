#include <iostream>
#include <array>
#include <vector>
#include <string>

using namespace std;

long long solve(long long n) {
  string s = to_string(n);
  vector<array<long long, 2>> dp(s.size() + 1);
  dp[0][0] = 1;
  dp[0][1] = 0;
  for (int i = 0; i < s.size(); i++) {
    int d = s[i] - '0';
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k <= (j == 1 ? 9 : d); k++) {
        if (k == 9 || k == 4) {
          continue;
        }

        dp[i + 1][j || (d > k)] += dp[i][j];
      }
    }
  }

  return n - dp[s.size()][0] - dp[s.size()][1];
}

int main(int argc, const char *argv[])
{
  long long a, b;
  cin >> a >> b;
  cout << solve(b) - solve(a - 1) << "\n";
  return 0;
}


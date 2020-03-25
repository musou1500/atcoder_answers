#include <iostream>
#include <cmath>
#include <utility>
#include <vector>
#include <iomanip>

using namespace std;

double calc_prob(int r1, int r2) {
  return 1. / (1. + pow(10., (r2 - r1) / 400.));
}

pair<int, int> candidate_range(int p, int i) {
  int l = p - p % (1 << i);
  int r = l + (1 << i);
  return make_pair(l, r);
}

double solve(int p, int k, vector<int> &ratings, vector<vector<double>> &memo) {
  if (memo[p][k] < 0) {
    auto range = candidate_range(p, k);
    auto prev_range = candidate_range(p, k - 1);
    double ans = 0;
    for (int i = range.first; i < range.second; i++) {
      if (i >= prev_range.first && i < prev_range.second) continue;
      ans += solve(p, k - 1, ratings, memo) * solve(i, k - 1, ratings, memo) * calc_prob(ratings[p], ratings[i]);
    }

    memo[p][k] = ans;
  }

  return memo[p][k];
}

int main(int argc, const char *argv[])
{
  int k;
  cin >> k;

  int n = 1 << k;
  vector<int> ratings(n);
  for (int i = 0; i < n; i++) cin >> ratings[i];

  vector<vector<double>> memo(n + 1, vector<double>(k + 1, -1));
  for (int i = 0; i < n; i++) memo[i][0] = 1;

  cout << fixed << setprecision(10);
  for (int i = 0; i < n; i++) cout << solve(i, k, ratings, memo) << "\n";
  return 0;
}

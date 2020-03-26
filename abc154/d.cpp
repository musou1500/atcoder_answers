#include <functional>
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <numeric>

using namespace std;

double calc_expectation(vector<int> &p, int offset, int len) {
  double ans = 0;
  for (int i = offset; i < offset + len; i++) {
    double num = p[i];
    ans += (num + 1) * num / 2 / num;
  }

  return ans;
}

int main(int argc, const char *argv[])
{
  int n, k;
  cin >> n >> k;

  vector<int> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }

  vector<int> csum{0};
  partial_sum(p.begin(), p.end(), back_inserter(csum));

  int idx, max_sum = 0;
  for (int i = 0; i <= n - k; i++) {
    int sum = csum[i + k] - csum[i];
    if (max_sum < sum) {
      max_sum = sum;
      idx = i;
    }
  }

  cout << fixed << setprecision(9) << calc_expectation(p, idx, k) << "\n";
  return 0;
}

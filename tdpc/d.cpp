#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <map>

using namespace std;

using ull = unsigned long long;
using MemoKey = tuple<ull, int, int, int>;
using Memo = map<MemoKey, double>;

array<int, 4> count_prime_factor(ull n) {
  array<int, 3> factors{2, 3, 5};
  array<int, 4> cnts{0};
  for (int i = 0; i < factors.size(); i++) {
    while (n % factors[i] == 0) {
      n /= factors[i];
      cnts[i]++;
    }
  }

  cnts[3] = n;
  return cnts;
}

double solve(ull n, int cnt2, int cnt3, int cnt5, Memo &memo) {
  if (cnt2 == 0 && cnt3 == 0 && cnt5 == 0) return 1;
  if (n == 0) return 0;

  MemoKey k = make_tuple(n, cnt2, cnt3, cnt5);
  if (memo.count(k) <= 0) {
    double ans = solve(n - 1, cnt2, cnt3, cnt5, memo);
    ans += solve(n - 1, max(cnt2 - 1, 0), cnt3, cnt5, memo);
    ans += solve(n - 1, cnt2, max(cnt3 - 1, 0), cnt5, memo);
    ans += solve(n - 1, max(cnt2 - 2, 0), cnt3, cnt5, memo);
    ans += solve(n - 1, cnt2, cnt3, max(cnt5 - 1, 0), memo);
    ans += solve(n - 1, max(cnt2 - 1, 0), max(cnt3 - 1, 0), cnt5, memo);
    memo[k] = ans / 6.;
  }

  return memo[k];
}

int main(int argc, const char *argv[])
{
  ull n, d;
  cin >> n >> d;

  Memo memo;
  array<int, 4> cnts = count_prime_factor(d);
  double ans = cnts[3] != 1 ? 0 : solve(n, cnts[0], cnts[1], cnts[2], memo);
  cout << fixed << setprecision(10);
  cout << ans << "\n";
  return 0;
}


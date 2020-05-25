#include <bits/stdc++.h>

using namespace std;

template <typename T, typename = typename std::enable_if<
                          std::is_integral<T>::value, T>::type>
map<T, int> prime_factorize(T n) {
  map<T, int> cnts{};
  if (n == 1) {
    return cnts;
  }

  T a = 2;
  while (n >= a * a) {
    int cnt = 0;
    while (n % a == 0) {
      n /= a;
      cnt++;
    }

    if (cnt > 0) {
      cnts[a] = cnt;
    }

    a++;
  }

  if (n != 1) {
    cnts[n] = 1;
  }

  return cnts;
}

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;

  map<int, int> factors;
  factors[1] = 1;
  for (int i = 2; i <= n; ++i) {
    auto f = prime_factorize(i);
    for (auto &p : f) {
      factors[p.first] += p.second;
    }
  }

  int cnt_3, cnt_5, cnt_15, cnt_25, cnt_75;
  cnt_3 = cnt_5 = cnt_15 = cnt_25 = cnt_75 = 0;
  for (auto p : factors) {
    p.second++;
    if (p.second >= 3) {
      cnt_3++;
    }

    if (p.second >= 5) {
      cnt_5++;
    }

    if (p.second >= 15) {
      cnt_15++;
    }

    if (p.second >= 25) {
      cnt_25++;
    }

    if (p.second >= 75) {
      cnt_75++;
    }
  }

  int ans = 0;
  // A_1 ^ 3  * A_2 ^ 5 * A_3 ^ 5
  ans += max(0, cnt_3 - 2) * max(0, cnt_5 * (cnt_5 - 1) / 2);

  // A_1 ^ 25 * A_2 ^ 3
  ans += max(0, cnt_3 - 1) * cnt_25;

  // A_1 ^ 15 * A_2 ^ 5
  ans += max(0, cnt_5 - 1) * cnt_15;

  // A_1 ^ 75
  ans += cnt_75;

  cout << ans << '\n';
  return 0;
}

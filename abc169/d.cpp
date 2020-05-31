#include <bits/stdc++.h>

using namespace std;
using ll = long long;

template <typename T, typename = typename std::enable_if<
                          std::is_integral<T>::value, T>::type>
vector<pair<T, int>> prime_factorize(T n) {
  vector<pair<T, int>> cnts{};
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
      cnts.push_back({a, cnt});
    }

    a++;
  }

  if (n != 1) {
    cnts.push_back({n, 1});
  }

  return cnts;
}

int main(int argc, const char *argv[]) {
  ll n;
  cin >> n;

  auto f = prime_factorize(n);
  ll ans = 0;
  for (auto &p : f) {
    ll sum = 0, cur = 1, cnt = 0;
    while (sum < p.second) {
      sum += cur++;
      cnt++;
    }

    if (sum > p.second) {
      sum--;
      cnt--;
    }

    ans += cnt;
  }

  cout << ans << '\n';
  return 0;
}

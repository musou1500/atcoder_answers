#include <bits/stdc++.h>

using namespace std;

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
  int n;
  cin >> n;
  if (n == 1) {
    cout << 1 << '\n';
    return 0;
  }

  map<int, int> cnts;
  for (int i = 2; i <= n; ++i) {
    auto factors = prime_factorize(i);
    for (auto &f : factors) {
      cnts[f.first] += f.second;
    }
  }

  long long ans = 1, md = 1e9 + 7;
  for (auto &p : cnts) {
    ans = (((p.second % md) + 1) % md) * ans;
    ans = ans % md;
  }

  cout << ans << '\n';
  return 0;
}

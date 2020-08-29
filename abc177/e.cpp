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
  //
  int n;
  cin >> n;
  vector<int> va(n);
  for (int i = 0; i < n; ++i) {
    cin >> va[i];
  }

  map<int, int> cnts;
  for (int i = 0; i < n; ++i) {
    auto factors = prime_factorize(va[i]);
    for (auto f : factors) {
      if (f.second > 0 && f.first != 1) {
        cnts[f.first]++;
      }
    }
  }

  bool pairwise_coprime = true;
  for (auto &p : cnts) {
    if (p.second >= 2) {
      pairwise_coprime = false;
      break;
    }
  }

  int g = va.front();
  for (int i = 0; i < n; ++i) {
    g = gcd(g, va[i]);
  }

  if (pairwise_coprime) {
    cout << "pairwise coprime" << '\n';
  } else if (!pairwise_coprime && g == 1) {
    cout << "setwise coprime" << '\n';
  } else {
    cout << "not coprime" << '\n';
  }

  return 0;
}

#include <iostream>
#include <type_traits>
#include <vector>

using namespace std;

template <class M, class N>
common_type_t<M, N> gcd(M a, N b) {
  if (b == 0) {
    return a;
  } else {
    return gcd(b, a % b);
  }
}

using ll = long long;

template <typename T, typename = typename std::enable_if<
                          std::is_integral<T>::value, T>::type>
vector<pair<T, int>> prime_factorize(T n) {
  vector<pair<T, int>> cnts{{1, 1}};
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
  ll a, b;
  cin >> a >> b;

  ll ab_gcd = gcd(a, b);
  auto prime_facts = prime_factorize(ab_gcd);
  cout << prime_facts.size() << '\n';
  return 0;
}


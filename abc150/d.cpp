#include <algorithm>
#include <iostream>
#include <numeric>
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

template <class M, class N>
common_type_t<M, N> lcm(M a, N b) {
  return a * b / gcd(a, b);
}

int main(int argc, const char *argv[]) {
  using ll = long long;
  int n, m;
  cin >> n >> m;
  m *= 2;

  vector<ll> va(n);
  for (auto &a : va) {
    cin >> a;
  }

  auto is_csm = [&](ll n) {
    return n <= m && all_of(va.begin(), va.end(), [&](auto a) {
             return n % a == 0 && n / a % 2 == 1;
           });
  };

  ll a_lcm = accumulate(va.begin(), va.end(), 1ll,
                        [](auto acc, auto cur) { return lcm(acc, cur); });
  ll min_csm = a_lcm;
  if (!is_csm(a_lcm)) {
    if (!is_csm(a_lcm * 2)) {
      cout << 0 << "\n";
      return 0;
    }

    min_csm *= 2;
  }

  ll ans = 1 + (m - min_csm) / (a_lcm * 2);
  cout << ans << "\n";
  return 0;
}

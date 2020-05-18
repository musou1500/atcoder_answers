#include <bits/stdc++.h>
#include <utility>

using namespace std;
using ll = long long;
const ll md = 1e9 + 7;

namespace mod {
template <class T, int M>
class MInt;

template <class T, int M>
MInt<T, M> Pow(const MInt<T, M> &base, T exp);

template <class T, int M>
MInt<T, M> Inv(const MInt<T, M> &n);

template <class T, int M>
class MInt {
  T n_;

 public:
  MInt() : n_(0) {}
  MInt(T n) : n_((n % M + M) % M) {}

  MInt &operator+=(const MInt &rhs) {
    n_ += rhs.n_;
    if (n_ >= M) {
      n_ -= M;
    }

    return *this;
  }

  MInt &operator-=(const MInt &rhs) {
    n_ += M - rhs.n_;
    if (n_ >= M) {
      n_ -= M;
    }

    return *this;
  }

  MInt &operator*=(const MInt &rhs) {
    n_ = n_ * rhs.n_ % M;
    return *this;
  }

  MInt &operator/=(const MInt &rhs) { return (*this) *= Inv(rhs); }

  T Get() { return n_; }
};

template <class T, int M>
MInt<T, M> operator-(const MInt<T, M> &lhs, const MInt<T, M> &rhs) {
  MInt<T, M> res(lhs);
  return res -= rhs;
}

template <class T, int M>
MInt<T, M> operator+(const MInt<T, M> &lhs, const MInt<T, M> &rhs) {
  MInt<T, M> res(lhs);
  return res += rhs;
}

template <class T, int M>
MInt<T, M> operator*(const MInt<T, M> &lhs, const MInt<T, M> &rhs) {
  MInt<T, M> res(lhs);
  return res *= rhs;
}

template <class T, int M>
MInt<T, M> operator/(const MInt<T, M> &lhs, const MInt<T, M> &rhs) {
  MInt<T, M> res(lhs);
  return res /= rhs;
}

template <class T, int M>
MInt<T, M> Pow(const MInt<T, M> &base, T exp) {
  if (exp == 0) {
    return 1;
  }

  auto a = Pow(base, exp / 2);
  a *= a;
  if (exp % 2 == 1) {
    a *= base;
  }

  return a;
}

template <class T, int M>
MInt<T, M> Inv(const MInt<T, M> &n) {
  return Pow(n, static_cast<T>(M - 2));
}
}  // namespace mod

using MInt = mod::MInt<long long, md>;

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;
  map<pair<ll, ll>, ll> m;
  MInt z_cnt(0);
  for (int i = 0; i < n; ++i) {
    ll a, b;
    cin >> a >> b;

    if (a == 0 && b == 0) {
      z_cnt += 1;
      continue;
    }

    if (a == 0) {
      m[make_pair(0, 1)]++;
      continue;
    } else if (b == 0) {
      m[make_pair(1, 0)]++;
      continue;
    }

    // a, bはどちらも0でない
    if (b < 0) {
      a *= -1;
      b *= -1;
    }

    ll ab_gcd = gcd(abs(a), abs(b));
    auto key = make_pair(a / ab_gcd, b / ab_gcd);
    m[key]++;
  }

  MInt ans(1), m2(2);
  set<pair<ll, ll>> used;
  for (auto [ab, ab_cnt] : m) {
    if (used.count(ab) > 0) {
      continue;
    }

    auto [a, b] = ab;
    pair<ll, ll> p;
    if (a == 0 || b == 0) {
      p.first = b;
      p.second = a;
    } else if (a < 0) {
      // ex.
      // -3, 1
      // -1, 3
      p.first = b;
      p.second = -a;
    } else {
      // ex.
      // 3, 1
      // -1, 3
      p.first = -b;
      p.second = a;
    }

    ans *= mod::Pow(m2, ab_cnt) + mod::Pow(m2, m[p]) - MInt(1);

    used.insert(p);
    used.insert(ab);
  }

  ans += z_cnt;
  ans -= 1;
  cout << ans.Get() << '\n';
  return 0;
}

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

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

const int md = 1e9 + 7;
using MInt = mod::MInt<long long, md>;
class BinCoef {
  vector<MInt> f;

 public:
  BinCoef(int n) : f(n + 1) {
    f[0] = f[1] = 1;
    for (int i = 2; i <= n; i++) {
      f[i] = MInt(i) * f[i - 1];
    }
  }

  MInt NCM(int n, int m) {
    if (n < m) {
      return 0;
    }
    return f[n] * mod::Inv(f[m] * f[n - m]);
  }

  MInt HCM(int n, int m) { return NCM(n + m - 1, m); }
};

int main(int argc, const char *argv[]) {
  ll k, n;
  string s;
  cin >> k >> s;
  n = s.size();

  BinCoef bc(n + k);
  MInt ans = 0;
  for (ll i = 0; i <= k; ++i) {
    auto now = mod::Pow(MInt(26), k - i);
    now *= mod::Pow(MInt(25), i);
    now *= bc.HCM(i + 1, n - 1);
    ans += now;
  }

  cout << ans.Get() << '\n';
  return 0;
}


#include <bits/stdc++.h>

using namespace std;

namespace tt::mod {

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

template <class T>
class BinCoef {
  std::vector<T> f;

 public:
  BinCoef(int n) : f(n + 1) {
    f[0] = f[1] = 1;
    for (int i = 2; i <= n; i++) {
      f[i] = T(i) * f[i - 1];
    }
  }

  T NCM(int n, int m) {
    if (n < m) {
      return 0;
    }
    return f[n] * mod::Inv(f[m] * f[n - m]);
  }

  T HCM(int n, int m) { return NCM(n + m - 1, m); }
  T NPM(int n, int m) { return f[n] / f[n - m]; }
};

}  // namespace tt::mod

const long long md = 1e9 + 7;
using MInt = tt::mod::MInt<long long, md>;
using tt::mod::Pow;

int main(int argc, const char *argv[]) {
  int t;
  cin >> t;

  vector<MInt> va;
  for (int i = 0; i < t; ++i) {
    long long n, a, b;
    cin >> n >> a >> b;
    if (n < a + b) {
      va.push_back(0);
    } else {
      auto x =
          Pow(MInt(n - a + 1) * MInt(n - b + 1) -
                  MInt(2) * MInt(n - a - b + 2) * MInt(n - a - b + 1) / MInt(2),
              2ll);
      auto ans = Pow(MInt(n - a + 1), 2ll) * Pow(MInt(n - b + 1), 2ll) - x;
      va.push_back(ans);
    }
  }

  for (auto a : va) {
    cout << a.Get() << '\n';
  }

  return 0;
}

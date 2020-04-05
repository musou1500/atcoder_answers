#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

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

  MInt NCM(int n, int m) { return f[n] * mod::Inv(f[m] * f[n - m]); }
};

int main(int argc, const char *argv[]) {
  int n, k;
  cin >> n >> k;
  vector<int> va(n);
  for (auto &a : va) {
    cin >> a;
  }

  sort(va.begin(), va.end());

  BinCoef bc(n);
  MInt ans(0);
  for (auto it = va.rbegin(); it != va.rend() - k + 1; it++) {
    int idx = distance(va.rbegin(), it);
    ans += MInt(*it) * bc.NCM(n - idx - 1, k - 1);
  }

  for (auto it = va.begin(); it != va.end() - k + 1; it++) {
    int idx = distance(va.begin(), it);
    ans -= MInt(*it) * bc.NCM(n - idx - 1, k - 1);
  }

  cout << ans.Get() << "\n";
  return 0;
}

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

int main(int argc, const char *argv[]) {
  ll n, m;
  cin >> n >> m;

  vector<ll> vx(n), vy(m);
  for (int i = 0; i < n; ++i) {
    cin >> vx[i];
  }

  for (int i = 0; i < m; ++i) {
    cin >> vy[i];
  }

  vector<MInt> vdx(n - 1), vdy(m - 1);
  for (int i = 1; i < n; ++i) {
    vdx[i - 1] = vx[i] - vx[i - 1];
  }

  for (int i = 1; i < m; ++i) {
    vdy[i - 1] = vy[i] - vy[i - 1];
  }

  MInt sx = accumulate(vdx.begin(), vdx.end(), MInt(0)),
       sy = accumulate(vdy.begin(), vdy.end(), MInt(0));

  MInt mn = n, mm = m;

  MInt ans1(0);
  for (int i = 0; i < vdx.size(); ++i) {
    ans1 += MInt(i + 1) * MInt(vdx.size() - i) * vdx[i];
  }

  MInt ans2(0);
  for (int i = 0; i < vdy.size(); ++i) {
    ans2 += MInt(i + 1) * MInt(vdy.size() - i) * vdy[i];
  }

  cout << (ans1 * ans2).Get() << '\n';

  return 0;
}

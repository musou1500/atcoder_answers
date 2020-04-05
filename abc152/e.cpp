#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <numeric>
#include <map>
#include <cmath>

using namespace std;


namespace mod {

template<class T, int M>
class MInt;

template<class T, int M>
MInt<T, M> Pow(const MInt<T, M> &base, T exp);

template<class T, int M>
MInt<T, M> Inv(const MInt<T, M> &n);

template<class T, int M>
class MInt {
  T n_;
public:
  MInt() : n_(0) {}
  MInt(T n) : n_((n % M + M) % M) {}

  MInt& operator+=(const MInt &rhs) {
    n_ += rhs.n_;
    if (n_ >= M) {
      n_ -= M;
    }

    return *this;
  }
  
  MInt& operator-=(const MInt &rhs) {
    n_ += M - rhs.n_;
    if (n_ >= M) {
      n_ -= M;
    }

    return *this;
  }

  MInt& operator*=(const MInt &rhs) {
    n_ = n_ * rhs.n_ % M;
    return *this;
  }

  MInt& operator/=(const MInt &rhs) {
    return (*this) *= Inv(rhs);
  }

  T Get() {
    return n_;
  }
};

template<class T, int M>
MInt<T, M> operator-(const MInt<T, M> &lhs, const MInt<T, M> &rhs) {
  MInt<T, M> res(lhs);
  return res -= rhs;
}

template<class T, int M>
MInt<T, M> operator+(const MInt<T, M> &lhs, const MInt<T, M> &rhs) {
  MInt<T, M> res(lhs);
  return res += rhs;
}

template<class T, int M>
MInt<T, M> operator*(const MInt<T, M> &lhs, const MInt<T, M> &rhs) {
  MInt<T, M> res(lhs);
  return res *= rhs;
}

template<class T, int M>
MInt<T, M> operator/(const MInt<T, M> &lhs, const MInt<T, M> &rhs) {
  MInt<T, M> res(lhs);
  return res /= rhs;
}

template<class T, int M>
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

template<class T, int M>
MInt<T, M> Inv(const MInt<T, M> &n) {
  return Pow(n, static_cast<T>(M - 2));
}
}


const int m = 1e9+7;
using ll = long long;
using MInt = mod::MInt<ll, m>;
using PrimeFactors = map<int, int>;

int main(int argc, const char *argv[])
{
  int n;
  cin >> n;

  vector<int> a(n);
  vector<int> lcm_factors(pow(10, 6) * 2, 0);
  auto update_lcm = [&](int n) {
    int prime = 2;
    for (int prime = 2; prime * prime <= n; prime++) {
      int cnt = 0;
      while (n % prime == 0) {
        n /= prime;
        cnt++;
      }

      if (cnt > 0) {
        lcm_factors[prime] = max(lcm_factors[prime], cnt);
      }
    }

    lcm_factors[n] = max(lcm_factors[n], 1);
  };

  for (int i = 0; i < n; i++) {
    cin >> a[i];
    update_lcm(a[i]);
  }

  MInt a_lcm(1);
  for (int i = 1; i < lcm_factors.size(); i++) {
    a_lcm *= mod::Pow(MInt(i), static_cast<ll>(lcm_factors[i]));
  }
  
  MInt ans = accumulate(a.begin(), a.end(), MInt(0),
      [&](const auto &acc, int cur) { return acc + a_lcm / MInt(cur); });
  cout << ans.Get() << "\n";
  return 0;
}


#include <iostream>
#include <vector>

using namespace std;

namespace mod {

const int mod = 1000000007;

class MInt;
MInt Pow(const MInt &base, long long exp);
MInt Inv(const MInt &n);

class MInt {
  long long n_;
public:
  MInt() : n_(0) {}
  MInt(long long n) : n_((n % mod + mod) % mod) {}

  MInt& operator+=(const MInt &rhs) {
    n_ += rhs.n_;
    if (n_ >= mod) {
      n_ -= mod;
    }

    return *this;
  }
  
  MInt& operator-=(const MInt &rhs) {
    n_ += mod - rhs.n_;
    if (n_ >= mod) {
      n_ -= mod;
    }

    return *this;
  }

  MInt& operator*=(const MInt &rhs) {
    n_ = n_ * rhs.n_ % mod;
    return *this;
  }

  MInt& operator/=(const MInt &rhs) {
    return (*this) *= Inv(rhs);
  }

  long long Get() {
    return n_;
  }
};

MInt operator-(const MInt &lhs, const MInt &rhs) {
  MInt res(lhs);
  return res -= rhs;
}

MInt operator+(const MInt &lhs, const MInt &rhs) {
  MInt res(lhs);
  return res += rhs;
}

MInt operator*(const MInt &lhs, const MInt &rhs) {
  MInt res(lhs);
  return res *= rhs;
}

MInt operator/(const MInt &lhs, const MInt &rhs) {
  MInt res(lhs);
  return res /= rhs;
}

MInt Pow(const MInt &base, long long exp) {
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

MInt Inv(const MInt &n) {
  return Pow(n, mod - 2);
}
}

int factorial(int n) {
  return n <= 1 ? 1 : factorial(n - 1) * n;
}

class BinCoef {
  vector<mod::MInt> f;
public:
  BinCoef(int n): f(n + 1) {
    f[0] = f[1] = 1;
    for (int i = 2; i <= n; i++) {
      f[i] = i * f[i - 1];
    }
  }

  mod::MInt NCM(int n, int m) {
    return f[n] * mod::Inv(f[m] * f[n - m]);
  }
};

int main(int argc, const char *argv[])
{
  int n, k;
  cin >> n >> k;
  k = min(k, n - 1);

  BinCoef bc(n);

  mod::MInt ans(0);
  for (int i = 0; i <= k; i++) {
    ans += bc.NCM(n, i) * bc.NCM(n - 1, i);
  }

  cout << ans.Get() << "\n";
}


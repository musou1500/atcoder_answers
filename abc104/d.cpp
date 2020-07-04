#include <bits/stdc++.h>

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

// |s| > |T|
MInt solve(string &s, string &t, int i, int j,
           vector<array<optional<MInt>, 4>> &memo) {
  if (i == s.size()) {
    return j == t.size();
  }

  if (!memo[i][j].has_value()) {
    MInt ans = solve(s, t, i + 1, j, memo);
    if (j < t.size() && s[i] == t[j]) {
      ans += solve(s, t, i + 1, j + 1, memo);
    }

    memo[i][j] = ans;
  }

  return memo[i][j]->Get();
}

int main(int argc, const char *argv[]) {
  string s, t;
  cin >> s;

  int s_qcnt = 0;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == '?') {
      s_qcnt++;
    }
  }

  vector<MInt> pow3(s_qcnt + 1);
  pow3[0] = 1;
  for (int i = 1; i < pow3.size(); ++i) {
    pow3[i] = pow3[i - 1] * MInt(3);
  }

  MInt ans = 0;
  for (int i = 0; i < (1 << 3); ++i) {
    string t = "ABC";
    int t_qcnt = 0;
    for (int j = 0; j < 3; ++j) {
      if (!(i & (1 << j))) {
        t[j] = '?';
        t_qcnt++;
      }
    }

    vector<array<optional<MInt>, 4>> memo(s.size() + 1);
    ans += solve(s, t, 0, 0, memo) * pow3[max(0, s_qcnt - t_qcnt)];
  }

  cout << ans.Get() << '\n';
  return 0;
}

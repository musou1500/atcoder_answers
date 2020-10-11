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

int count_seq(vector<string> &g, int h, int w, int i, int j, int step_v,
              int step_h) {
  if (i >= h || j >= w || g[i][j] == '#') {
    return 0;
  } else {
    return count_seq(g, h, w, i + step_v, j + step_h, step_v, step_h) + 1;
  }
}

const long long md = 1e9 + 7;
using ll = long long;
using MInt = tt::mod::MInt<long long, md>;
using tt::mod::Pow;

int main(int argc, const char *argv[]) {
  int h, w;
  cin >> h >> w;

  vector<string> g(h);
  for (int i = 0; i < h; ++i) {
    cin >> g[i];
  }

  vector<vector<int>> cnt_h, cnt_v;
  cnt_h = cnt_v = vector<vector<int>>(h, vector<int>(w, 0));

  vector<vector<int>> memo1, memo2;
  memo1 = memo2 = vector<vector<int>>(h, vector<int>(w, -1));

  for (int i = 0; i < h; ++i) {
    int cur = 0;
    while (cur < w) {
      if (g[i][cur] == '.') {
        int cnt = count_seq(g, h, w, i, cur, 0, 1);
        fill(cnt_h[i].begin() + cur, cnt_h[i].begin() + cur + cnt, cnt);
        cur += cnt;
      } else {
        cur++;
      }
    }
  }

  for (int i = 0; i < w; ++i) {
    int cur = 0;
    while (cur < h) {
      if (g[cur][i] == '.') {
        int cnt = count_seq(g, h, w, cur, i, 1, 0);
        for (int j = 0; j < cnt; ++j) {
          cnt_v[cur + j][i] = cnt;
        }
        cur += cnt;
      } else {
        cur++;
      }
    }
  }

  ll k = accumulate(g.begin(), g.end(), 0, [](auto a, auto b) {
    return a + count(b.begin(), b.end(), '.');
  });

  MInt ans = MInt(k) * Pow(MInt(2), k);

  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (g[i][j] == '.') {
        int cnt = cnt_h[i][j] + cnt_v[i][j] - 1;
        ans -= Pow(MInt(2), k - cnt);
      }
    }
  }

  cout << ans.Get() << '\n';
  return 0;
}

#include <bits/stdc++.h>
#include <atcoder/all>
#include <atcoder/modint.hpp>
#include <vector>

using namespace std;
const int md = 998244353;
using ll = long long;
using MInt = atcoder::modint998244353;
// using MInt = ll;

int main(int argc, const char *argv[]) {
  int n, q;
  cin >> n >> q;

  MInt digit = 1, ans = 0;
  vector<MInt> d_psum{0, digit};
  vector<MInt> vd{0, digit};
  for (int i = 0; i < n; ++i) {
    ans += digit;
    digit *= 10;
    d_psum.push_back(digit + d_psum.back());
  }

  vector<MInt> pow10{1};
  for (int i = 0; i < n; ++i) {
    pow10.push_back(pow10.back() * MInt(10));
  }

  cout << ((MInt(1234) / MInt(100)) * MInt(100)).val() << '\n';
  vector<MInt> lines;
  for (int i = 0; i < q; ++i) {
    int l, r, d;
    cin >> l >> r >> d;

    auto ans_sub = (ans / pow10[n - r]) * pow10[n - r];
    ans_sub -= (ans / pow10[n - l + 1]) * pow10[n - l + 1];

    auto sum_sub = (d_psum[n] / pow10[n - r]) * pow10[n - r];
    sum_sub -= (d_psum[n] / pow10[n - l + 1]) * pow10[n - l + 1];

    sum_sub *= d;

    ans -= ans_sub - sum_sub;
    lines.push_back(ans);
  }

  for (int i = 0; i < lines.size(); ++i) {
    cout << lines[i].val() << '\n';
  }

  return 0;
}

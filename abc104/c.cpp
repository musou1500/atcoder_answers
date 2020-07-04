#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(int argc, const char *argv[]) {
  int d;
  ll g;
  cin >> d >> g;

  vector<pair<ll, ll>> v_pc(d);
  for (auto &p : v_pc) {
    cin >> p.first >> p.second;
  }

  ll ans = -1;
  for (int i = 0; i < (1 << d); ++i) {
    ll sum = 0, cnt = 0;

    // フラグが立っている配点の問題は全て解く
    for (int j = 0; j < d; ++j) {
      if (i & (1 << j)) {
        ll pt = (j + 1) * 100;
        sum += v_pc[j].second + v_pc[j].first * pt;
        cnt += v_pc[j].first;
      }
    }

    // その他の問題
    for (int j = d - 1; j >= 0 && sum < g; --j) {
      if (i & (1 << j)) {
        continue;
      }

      ll remain = g - sum;
      ll pt = (j + 1) * 100;
      ll cnt2 = min(v_pc[j].first, remain / pt + (remain % pt != 0));
      cnt += cnt2;
      sum += pt * cnt2;
    }

    if (ans < 0 || ans > cnt) {
      ans = cnt;
    }
  }

  cout << ans << '\n';
}

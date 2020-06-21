#include <bits/stdc++.h>
#include <vector>

using namespace std;
using ll = long long;

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;
  vector<bitset<64>> va(n);
  for (int i = 0; i < n; ++i) {
    ll a;
    cin >> a;
    va[i] = bitset<64>(a);
  }

  // 各桁ごとの1の出現回数
  vector<int> v_cnt(64, 0);
  for (int i = 0; i < 64; ++i) {
    for (int j = 0; j < n; ++j) {
      auto &bs = va[j];
      v_cnt[i] += bs[i];
    }
  }

  for (int i = 0; i < 64; ++i) {
    bool rev = v_cnt[i] % 2 == 1;
    for (int j = 0; j < n; ++j) {
      // A_jのi桁目を決定する
      if (rev) {
        auto &bs = va[j];
        bs[i] = bs[i] == 0 ? 1 : 0;
      }
    }
  }

  for (int i = 0; i < va.size(); ++i) {
    cout << va[i].to_ullong() << '\n';
  }
  return 0;
}

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;
  int max_a = 100000;
  ll sum = 0;
  vector<ll> v_cnt(max_a + 1, 0), va(n);
  for (int i = 0; i < n; ++i) {
    cin >> va[i];
    v_cnt[va[i]]++;
    sum += va[i];
  }

  int q;
  cin >> q;
  vector<ll> ans;
  for (int i = 0; i < q; ++i) {
    int b, c;
    cin >> b >> c;
    ll cnt = v_cnt[b];
    v_cnt[b] = 0;
    v_cnt[c] += cnt;
    sum -= b * cnt;
    sum += c * cnt;
    ans.push_back(sum);
  }

  for (int i = 0; i < ans.size(); ++i) {
    cout << ans[i] << '\n';
  }

  return 0;
}

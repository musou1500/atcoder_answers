#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(int argc, const char *argv[]) {
  int n, m;
  cin >> n;
  cin >> m;

  vector<ll> vh(n);
  for (int i = 0; i < n; ++i) {
    cin >> vh[i];
  }

  vector<ll> vw(m);
  for (int i = 0; i < m; ++i) {
    cin >> vw[i];
  }

  sort(vh.begin(), vh.end());
  sort(vw.begin(), vw.end());

  vector<ll> sum1{0}, sum2{0};
  for (int i = 0; i < n - 1; ++i) {
    if (i % 2 == 0) {
      sum1.push_back(sum1.back() + abs(vh[i] - vh[i + 1]));
      sum2.push_back(sum2.back());
    } else {
      sum2.push_back(sum2.back() + abs(vh[i] - vh[i + 1]));
      sum1.push_back(sum1.back());
    }
  }

  // どこを無視するか固定する
  int ans;
  for (int i = 0; i < n; ++i) {
    // その他の合計
    ll sum = 0;
    if (i % 2 == 1) {
      sum += sum1[i - 1];
      sum += vh[i - 1] + vh[i + 1];
      sum += sum2.back();
      if (i + 2 < sum2.size()) {
        sum -= sum2[i + 2];
      } else {
        sum -= sum2.back();
      }
    } else {
      sum += sum1[i];
      sum += sum2.back();
      if (i + 1 < sum2.size()) {
        sum -= sum2[i + 1];
      } else {
        sum -= sum2.back();
      }
    }

    // vwからselに最も近い要素を探す
    auto lb = lower_bound(vw.begin(), vw.end(), vh[i]);
    if (lb == vw.end()) {
      sum += abs(vh[i] - vw.back());
    } else if (lb == vw.begin()) {
      sum += abs(vh[i] - vw.front());
    } else {
      ll m = abs(*lb - vh[i]);
      m = min(m, abs(*(lb - 1) - vh[i]));
      sum += m;
    }

    if (i == 0 || ans > sum) {
      ans = sum;
    }
  }

  cout << ans << '\n';

  return 0;
}

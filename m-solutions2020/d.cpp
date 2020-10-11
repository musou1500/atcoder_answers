#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(int argc, const char *argv[]) {
  ll n;
  cin >> n;

  vector<ll> va(n);
  for (ll i = 0; i < n; ++i) {
    cin >> va[i];
  }

  ll cur = 0, money = 1000, k = 0;
  bool b = true;
  vector<ll> ans{1000};
  while (cur < n) {
    ll i = cur;
    if (b) {
      // 増えるところを見つける
      while (i < n - 1 && va[i] > va[i + 1]) {
        i++;
      }

      // 全て買う
      ll cnt = money / va[i];
      money -= va[i] * cnt;
      k += cnt;
      ans.push_back(money);
    } else {
      // 減るところを見つける
      while (i < n - 1 && va[i] <= va[i + 1]) {
        i++;
      }

      // 全て売る
      money += va[i] * k;
      k = 0;
      ans.push_back(money);
    }

    b = !b;
    cur = i + 1;
  }

  cout << *max_element(ans.begin(), ans.end()) << '\n';
  return 0;
}

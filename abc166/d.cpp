#include <bits/stdc++.h>
#include <algorithm>
#include <iterator>

using namespace std;

int main(int argc, const char *argv[]) {
  using ll = long long;
  ll x;
  cin >> x;

  vector<ll> memo;
  for (ll i = 0; i < 1000; ++i) {
    memo.push_back(pow(i, 5));
  }

  ll a, b;
  for (ll i = 0; i < memo.size(); ++i) {
    // a^5 + b^5 = x
    auto add_it = lower_bound(memo.begin(), memo.end(), x - memo[i]);
    if (add_it != memo.end() && *add_it == x - memo[i]) {
      a = i;
      b = -distance(memo.begin(), add_it);
      break;
    }

    // a^5 - b^5 = x
    auto sub_it = lower_bound(memo.begin(), memo.end(), memo[i] - x);
    if (sub_it != memo.end() && *sub_it == memo[i] - x) {
      a = i;
      b = distance(memo.begin(), sub_it);
      break;
    }
  }

  cout << a << ' ' << b << '\n';

  return 0;
}

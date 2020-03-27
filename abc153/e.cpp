#include <iostream>
#include <limits>
#include <vector>

using namespace std;

using ll = long long;

int solve(ll hp, vector<pair<ll, ll>> &pairs, vector<ll> &memo) {
  if (hp <= 0) {
    return 0;
  }

  if (memo[hp] < 0) {
    ll ans = numeric_limits<ll>::max();
    for (auto p : pairs) {
      ans = min(ans, solve(hp - p.first, pairs, memo) + p.second);
    }

    memo[hp] = ans;
  }

  return memo[hp];
}

int main(int argc, const char *argv[])
{
  ll h;
  int n;
  cin >> h >> n;

  vector<pair<ll, ll>> pairs(n);
  for (int i = 0; i < n; i++) {
    // 減らせる体力, 消費MP
    cin >> pairs[i].first >> pairs[i].second;
  }

  vector<ll> memo(h + 1, -1);

  cout << solve(h, pairs, memo) << "\n";
  
  return 0;
}

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int md = 1e9 + 7;
using pll = pair<ll, ll>;

int main(int argc, const char *argv[]) {
  ll n, k;
  cin >> n >> k;

  // 正の数，負の数
  vector<ll> va;
  bool has_z = false;
  for (int i = 0; i < n; ++i) {
    ll a;
    cin >> a;
    va.push_back(a);
  }

  sort(va.begin(), va.end(), greater<ll>());

  // 積を (10^9)+7 で割った商と余りで表す
  vector<pair<ll, ll>> vmult;

  // 正と負
  // 負と負
  // 正と負
  // ゼロ
  return 0;
}

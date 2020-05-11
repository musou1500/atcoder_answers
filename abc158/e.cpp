#include <array>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, const char *argv[]) {
  using ll = long long;
  ll n, p;
  string s;
  cin >> n >> p >> s;

  ll ans = 0;
  if (p == 2 || p == 5) {
    for (int i = 0; i < s.size(); ++i) {
      int d = s[i] - '0';
      if (d % p != 0) {
        continue;
      }

      ans += i + 1;
    }

    cout << ans << '\n';
    return 0;
  }

  vector<ll> mods(p, 0);
  mods[0] = 1;

  ll md = 0, pow10 = 1;
  for (int i = s.size() - 1; i >= 0; --i) {
    ll d = s[i] - '0';
    md = (pow10 * d + md) % p;
    mods[md]++;
    pow10 = pow10 * 10 % p;
  }

  for (int i = 0; i < mods.size(); ++i) {
    if (mods[i] >= 2) {
      ans += mods[i] * (mods[i] - 1) / 2;
    }
  }

  cout << ans << "\n";
}

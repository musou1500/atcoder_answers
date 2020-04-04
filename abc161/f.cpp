#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

vector<ll> get_divisors(ll n) {
  vector<ll> ans;
  for (ll i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      ans.push_back(i);
      if (i * i != n) {
        ans.push_back(n / i);
      }
    }
  }

  return ans;
}

ll divsub(ll n, ll k) {
  ll mod = n % k;
  return mod == 0 ? divsub(n / k, k) : mod;
}

int main(int argc, const char *argv[])
{
  ll n;
  cin >> n;

  ll ans = get_divisors(n - 1).size() - 1;
  auto divisors = get_divisors(n);
  for (auto divisor : divisors) {
    if (divisor != 1 && divsub(n, divisor) == 1) {
      ans++;
    }
  }

  cout << ans << "\n";
  return 0;
}

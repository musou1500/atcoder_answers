#include <iostream>

using namespace std;

int main(int argc, const char *argv[]) {
  using ll = long long;
  ll n;

  cin >> n;

  ll ans = n - 1;
  for (ll i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      ans = min(ans, i + n / i - 2);
    }
  }

  cout << ans << '\n';
  return 0;
}

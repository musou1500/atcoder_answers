#include <iostream>

using namespace std;

int main(int argc, const char *argv[])
{
  using ll = long long;
  ll n, k;
  cin >> n >> k;
  ll d = n / k;
  ll ans = min(n - d * k, abs(n - (d + 1) * k));
  cout << ans << "\n";
  return 0;
}

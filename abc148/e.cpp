#include <cmath>
#include <iostream>

using namespace std;

using ull = unsigned long long;

int main(int argc, const char *argv[]) {
  ull n;
  cin >> n;

  if (n % 2 == 1) {
    cout << 0 << '\n';
    return 0;
  }

  n /= 2;
  ull ans = 0;
  while (n != 0) {
    ans += n / 5;
    n /= 5;
  }

  cout << ans << '\n';
  return 0;
}

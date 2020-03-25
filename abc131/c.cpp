#include <iostream>

using namespace std;

using ull = unsigned long long;

ull gcd(ull a, ull b) {
  if (b == 0) {
    return a;
  } else {
    return gcd(b, a % b);
  }
}

int main(int argc, const char *argv[])
{
  ull a, b, c, d;
  cin >> a >> b >> c >> d;

  ull lcm = c * d / gcd(c, d);
  ull ans = b - a + 1;
  ull divisable = b / c + b / d - b / lcm;
  a--;
  divisable -= a / c + a / d - a / lcm;
  cout << ans - divisable << "\n";
  return 0;
}

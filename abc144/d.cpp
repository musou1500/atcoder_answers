#include <cmath>
#include <iomanip>
#include <ios>
#include <iostream>

const double PI = 3.14159265358979323846;

using namespace std;

int main(int argc, const char *argv[]) {
  double a, b, x;
  cin >> a >> b >> x;
  x /= a;

  double ans;
  if (a * b > 2 * x) {
    double c = 2 * (x / b);
    ans = 90 - atan(c / b) * 180 / PI;
  } else {
    double c = (2 * x) / a - b;
    ans = 90 - atan(a / (b - c)) * 180 / PI;
  }
  cout << fixed << setprecision(9) << ans << '\n';
  return 0;
}

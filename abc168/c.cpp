#include <bits/stdc++.h>

using namespace std;

const double pi = 3.141592653589793;

int main(int argc, const char *argv[]) {
  double a, b, h, m;
  cin >> a >> b >> h >> m;
  double m_rad = (m * 6);
  double h_rad = (h + m / 60.) * 30.;
  double theta = abs(m_rad - h_rad);
  theta /= 180.;
  theta *= pi;
  double ans = a * a + b * b - 2. * a * b * cos(theta);
  cout << fixed << setprecision(9) << sqrt(ans) << '\n';
  return 0;
}

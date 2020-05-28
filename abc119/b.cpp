#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;

  double sum = 0;
  for (int i = 0; i < n; ++i) {
    double x;
    cin >> x;
    string s;
    cin >> s;
    if (s == "JPY") {
      sum += x;
    } else {
      sum += 380000.0 * x;
    }
  }

  cout << fixed << setprecision(9) << sum << '\n';
  return 0;
}

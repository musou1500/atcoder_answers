#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(int argc, const char *argv[]) {
  ll a, b, c, d;
  cin >> a >> b >> c >> d;

  if ((b < c || a > d) || (d < a || c > b)) {
    cout << "No" << '\n';
  } else {
    cout << "Yes" << '\n';
  }

  return 0;
}

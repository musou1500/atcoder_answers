#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(int argc, const char *argv[]) {
  ll n;
  cin >> n;
  if (n % 2 == 0) {
    cout << n << '\n';
  } else {
    cout << n * 2 << '\n';
  }

  return 0;
}

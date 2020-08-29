#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(int argc, const char *argv[]) {
  //
  ll d, t, s;
  cin >> d >> t >> s;
  bool ans = s * t >= d;
  cout << (ans ? "Yes" : "No") << '\n';
  return 0;
}

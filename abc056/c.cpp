#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(int argc, const char *argv[]) {
  ll x;
  cin >> x;

  ll cur = 1;
  while (cur * (cur + 1) / 2 < x) {
    cur++;
  }

  cout << cur << '\n';
  return 0;
}

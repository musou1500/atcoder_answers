#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(int argc, const char *argv[]) {
  ll a, b, c, d;
  cin >> a >> b >> c >> d;
  vector<ll> nums{a * c, a * d, b * c, b * d};
  cout << *max_element(nums.begin(), nums.end()) << '\n';
  return 0;
}

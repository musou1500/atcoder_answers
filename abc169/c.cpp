#include <bits/stdc++.h>
#include <string>

using namespace std;

using ll = long long;
int main(int argc, const char *argv[]) {
  ll a, b, c;
  char dot;
  cin >> a >> b >> dot >> c;

  ll ans = a * b;
  string s_c = to_string(c * a);
  if (s_c.size() <= 2) {
    cout << ans << '\n';
    return 0;
  }

  ans += stoll(s_c.substr(0, s_c.size() - 2));
  cout << ans << '\n';
  return 0;
}

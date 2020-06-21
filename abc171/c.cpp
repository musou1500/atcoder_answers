#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  long long n;
  cin >> n;

  string ans;
  while (n > 0) {
    long long d = n % 26;
    n--;
    n /= 26;
    if (d == 0) {
      ans += 'z';
    } else {
      ans += 'a' + (d - 1);
    }
  }

  reverse(ans.begin(), ans.end());
  cout << ans << '\n';
  return 0;
}

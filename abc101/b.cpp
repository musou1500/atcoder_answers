#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(int argc, const char *argv[]) {
  ll n;
  cin >> n;

  string s = to_string(n);
  int sum = 0;
  for (int i = 0; i < s.size(); ++i) {
    int d = s[i] - '0';
    sum += d;
  }

  if (n % sum == 0) {
    cout << "Yes" << '\n';
  } else {
    cout << "No" << '\n';
  }

  return 0;
}

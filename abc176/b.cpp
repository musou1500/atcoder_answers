#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(int argc, const char *argv[]) {
  //
  string s;
  cin >> s;

  ll sum = 0;
  for (int i = 0; i < s.size(); ++i) {
    sum += s[i] - '0';
  }

  cout << (sum % 9 == 0 ? "Yes" : "No") << '\n';
  return 0;
}

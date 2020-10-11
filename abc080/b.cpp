#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;

  string s = to_string(n);
  int sum = 0;
  for (int i = 0; i < s.size(); ++i) {
    sum += s[i] - '0';
  }

  cout << (n % sum == 0 ? "Yes" : "No") << '\n';
  return 0;
}

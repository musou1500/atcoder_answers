#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  string s;
  cin >> s;

  int acc = 0;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == '+') {
      acc++;
    } else {
      acc--;
    }
  }

  cout << acc << '\n';
  return 0;
}

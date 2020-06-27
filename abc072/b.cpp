#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  string s;
  cin >> s;
  for (int i = 0; i < s.size(); i += 2) {
    cout << s[i];
  }

  cout << '\n';
  return 0;
}

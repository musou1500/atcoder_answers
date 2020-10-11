#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int main(int argc, const char *argv[]) {
  string s;
  cin >> s;
  if (s.size() == 3) {
    reverse(s.begin(), s.end());
  }

  cout << s << '\n';
  return 0;
}

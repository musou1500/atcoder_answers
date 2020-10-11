#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  //
  string s;
  cin >> s;
  if (s.back() == 's') {
    cout << s << "es" << '\n';
  } else {
    cout << s << 's' << '\n';
  }

  return 0;
}

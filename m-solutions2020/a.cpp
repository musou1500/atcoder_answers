#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int x;
  cin >> x;
  if (x <= 599) {
    cout << 8 << '\n';
  } else if (x <= 799) {
    cout << 7 << '\n';
  } else if (x <= 999) {
    cout << 6 << '\n';
  } else if (x <= 1199) {
    cout << 5 << '\n';
  } else if (x <= 1399) {
    cout << 4 << '\n';
  } else if (x <= 1599) {
    cout << 3 << '\n';
  } else if (x <= 1799) {
    cout << 2 << '\n';
  } else if (x <= 1999) {
    cout << 1 << '\n';
  }

  return 0;
}
